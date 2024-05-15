#define NEWLINE "\r\n"

static char const * const format_string_partidos =
"["
"{"
"  \"estadio\": %s," NEWLINE // (ENTRE 0 Y 19)
"  \"duracion\": %d," NEWLINE //(EN MINUTOS)
"  \"participantes\": {" NEWLINE
"	\"bots\": {" NEWLINE
"	  \"arbitro\": %s," NEWLINE //(ENTRE 0 Y 2)
"	  \"comentarista_1\": %s," NEWLINE // (ENTRE 0 Y 3)
"	  \"comentarista_2\": %s," NEWLINE // (ENTRE 0 Y 3)
"	}," NEWLINE
"	\"jugadores\": {" NEWLINE
"	  \"jugador_1\": %d," NEWLINE
"	  \"jugador_2\": %d" NEWLINE
"	}" NEWLINE
"  }," NEWLINE
"  \"resultado\": {" NEWLINE
"	\"goles_jugador_1\": %d," NEWLINE
"	\"goles_jugador_2\": %d" NEWLINE
"  }" NEWLINE
"}" NEWLINE
"]" NEWLINE
;

#undef NEWLINE
