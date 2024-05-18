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

void gen_file_jugador(char const *filename, int idx)
{
	FILE *file;
	file = fopen(filename, "wb");
	
	if(file == NULL)
		return;
	
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
	
	fclose(file);
}

void gen_file_partido(char const *filename, int idx, int maxidx)
{
	FILE *file;
	file = fopen(filename, "wb");
	
	if (file == NULL)
		return;
	
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
	
	fclose(file);
}

void gen_files(int amount)
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

int main(int argc, char **argv)
{
	if (argc != 2)
		fprintf(stderr, "usage: %s <amount>\n", argv[0]);
	int amount = atoi(argv[1]);
	srand(time(0));
	gen_files(amount);
	return 0;
}
