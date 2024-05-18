#ifndef FORMAT_STRING_PARTIDOS
#define FORMAT_STRING_PARTIDOS

#include "format_string.h"

static char const * const format_string_partidos =
""                                                                        FORMAT_STRING_NEWLINE
"{"                                                                       FORMAT_STRING_NEWLINE
"    \"estadio\": {%s}," /* (ENTRE 0 Y 19) */                             FORMAT_STRING_NEWLINE
"    \"duracion\": %d," /* (EN MINUTOS) */                                FORMAT_STRING_NEWLINE
"    \"participantes\": {"                                                FORMAT_STRING_NEWLINE
"        \"bots\": {"                                                     FORMAT_STRING_NEWLINE
"            \"arbitro\": {%s}," /* (ENTRE 0 Y 2) */                      FORMAT_STRING_NEWLINE
"            \"comentarista_1\": {%s}," /* (ENTRE 0 Y 3) */               FORMAT_STRING_NEWLINE
"            \"comentarista_2\": {%s}" /* (ENTRE 0 Y 3) */                FORMAT_STRING_NEWLINE
"        },"                                                              FORMAT_STRING_NEWLINE
"        \"jugadores\": {"                                                FORMAT_STRING_NEWLINE
"            \"jugador_1\": %d,"                                          FORMAT_STRING_NEWLINE
"            \"jugador_2\": %d"                                           FORMAT_STRING_NEWLINE
"        }"                                                               FORMAT_STRING_NEWLINE
"    },"                                                                  FORMAT_STRING_NEWLINE
"    \"resultado\": {"                                                    FORMAT_STRING_NEWLINE
"        \"goles_jugador_1\": %d,"                                        FORMAT_STRING_NEWLINE
"        \"goles_jugador_2\": %d"                                         FORMAT_STRING_NEWLINE
"    }"                                                                   FORMAT_STRING_NEWLINE
"}"                                                                       FORMAT_STRING_NEWLINE
""                                                                        FORMAT_STRING_NEWLINE
""                                                                        FORMAT_STRING_NEWLINE
;

#endif
