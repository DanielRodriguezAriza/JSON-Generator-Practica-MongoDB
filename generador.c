#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"
#include "format_string_jugador.h"
#include "format_string_partidos.h"
#include "lista_nombres_jugador.h"
#include "oid.h"

char const *get_random_player_name()
{
	return player_names[get_random_int(0, player_names_length - 1)];
}

char const *get_random_futbolista_oid()
{
	return oids_futbolistas[get_random_int(0, oids_futbolistas_length - 1)];
}

char const *get_random_entrenador_oid()
{
	return oids_entrenadores[get_random_int(0, oids_entrenadores_length - 1)];
}

#define FUTBOLISTAS_11 get_random_futbolista_oid(),\
get_random_futbolista_oid(),\
get_random_futbolista_oid(),\
get_random_futbolista_oid(),\
get_random_futbolista_oid(),\
get_random_futbolista_oid(),\
get_random_futbolista_oid(),\
get_random_futbolista_oid(),\
get_random_futbolista_oid(),\
get_random_futbolista_oid(),\
get_random_futbolista_oid()

#define EXPAND(x) x

void write_file_jugador(FILE *file, int idx)
{
	char const *nombre_jugador = player_names[idx % player_names_length];
	char const *nombre_foto = nombre_jugador;
	float dinero = get_random_float(100, 1000);
	int victorias = get_random_int(0, 20);
	int derrotas = get_random_int(0, 20);
	int empates = get_random_int(0, 20);
	char const *nombre_equipo = nombre_jugador;
	char const *nombre_escudo = nombre_jugador;
	char const *entrenador = get_random_entrenador_oid();
	
	fprintf(file, format_string_jugador,
		idx,
		nombre_jugador,
		nombre_foto,
		dinero,
		victorias,
		derrotas,
		empates,
		nombre_equipo,
		nombre_escudo,
		entrenador,
		EXPAND(FUTBOLISTAS_11)
	);
}

void gen_file_jugador(char const *filename, int idx)
{
	FILE *file;
	file = fopen(filename, "wb");
	
	if(file == NULL)
		return;
	
	fprintf(file, "[\r\n");
	write_file_jugador(file, idx);
	fprintf(file, "]\r\n");
	
	fclose(file);
}

void write_file_partido(FILE *file, int idx, int maxidx)
{
	char const *estadio = GET_RANDOM_OID(oids_estadios, oids_estadios_length);
	int duracion = get_random_int(40, 180); /* duración en minutos */
	oid arbitro = GET_RANDOM_OID(oids_arbitros, oids_arbitros_length);
	int comentarista_1_idx = get_random_int(1, oids_comentaristas_length - 1);
	oid comentarista_1 = oids_comentaristas[comentarista_1_idx];
	oid comentarista_2 = oids_comentaristas[comentarista_1_idx - 1];
	int jugador_1 = get_random_int(0, maxidx);
	int jugador_2 = idx;
	if (jugador_1 == jugador_2)
	{
		jugador_1 += jugador_1 > 0 ? -1 : 1;
	}
	int goles_1 = get_random_int(0, 10);
	int goles_2 = get_random_int(0, 10);
	
	fprintf(file, format_string_partidos,
		estadio,
		duracion,
		arbitro,
		comentarista_1,
		comentarista_2,
		jugador_1,
		jugador_2,
		goles_1,
		goles_2
	);
}

void gen_file_partido(char const *filename, int idx, int maxidx)
{
	FILE *file;
	file = fopen(filename, "wb");
	
	if (file == NULL)
		return;
	
	fprintf(file, "[\r\n");
	write_file_partido(file, idx, maxidx);
	fprintf(file, "]\r\n");
	
	fclose(file);
}

/* Generates one file for each entry */
void gen_files_multiple(int amount)
{
	char buf[255] = {0};
	
	for (int i = 0; i < amount; ++i)
	{
		snprintf(buf, 255, "./jugadores/%d-persona.json\0", i);
		gen_file_jugador(buf, i);
	}
	
	for (int i = 0; i < amount; ++i)
	{
		snprintf(buf, 255, "./partidos/%d-partido.json\0", i);
		gen_file_partido(buf, i, amount - 1);
	}
}

/* Generates one file with all entries */
void gen_files_single(int amount)
{
	char const filename_jugadores[] = "./jugadores/000-JUGADORES.json\0";
	char const filename_partidos[] = "./partidos/000-PARTIDOS.json\0";
	
	FILE *file_jugadores = fopen(filename_jugadores, "wb");
	FILE *file_partidos = fopen(filename_partidos, "wb");
	
	if (file_jugadores == NULL || file_partidos == NULL)
		return;
	
	fprintf(file_jugadores, "[\r\n");
	for (int i = 0; i < amount; ++i)
	{
		write_file_jugador(file_jugadores, i);
		if (i < amount - 1)
			fprintf(file_jugadores, ",\r\n");
	}
	fprintf(file_jugadores, "]\r\n");
	
	fprintf(file_partidos, "[\r\n");
	for (int i = 0; i < amount; ++i)
	{
		write_file_partido(file_partidos, i, amount - 1);
		if (i < amount - 1)
			fprintf(file_partidos, ",\r\n");
	}
	fprintf(file_partidos, "]\r\n");
}


void gen_files(int amount, int flag)
{
	printf("Generating %d entries.\n", amount);
	switch(flag)
	{
		default:
			fprintf(stderr, "Unknown flag used.\n");
			return;
			break;
		case 0:
			printf("Generating one individual file for each entry.");
			gen_files_multiple(amount);
			break;
		case 1:
			printf("Generating a single file containing all entries.");
			gen_files_single(amount);
			break;
	}
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		fprintf(stderr, "usage: %s <amount> <0: multiple files, 1: single file>\n", argv[0]);
		return 1;
	}
	int amount = atoi(argv[1]);
	int flag = atoi(argv[2]);
	srand(time(0));
	gen_files(amount, flag);
	return 0;
}
