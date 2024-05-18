#ifndef FORMAT_STRING_JUGADOR_H
#define FORMAT_STRING_JUGADOR_H

#include "format_string.h"

static char const * const format_string_jugador =
"["                                                                        FORMAT_STRING_NEWLINE
"{"                                                                        FORMAT_STRING_NEWLINE
"    \"_id\": %d,"                                                         FORMAT_STRING_NEWLINE
"    \"nombre\": \"%s\","                                                  FORMAT_STRING_NEWLINE
"    \"foto\": \"./imagenes/perfil/%s.png\","                              FORMAT_STRING_NEWLINE
"    \"dinero\": %f,"                                                      FORMAT_STRING_NEWLINE
"    \"trayectoria\": {"                                                   FORMAT_STRING_NEWLINE
"        \"victorias\": %d,"                                               FORMAT_STRING_NEWLINE
"        \"derrotas\": %d,"                                                FORMAT_STRING_NEWLINE
"        \"empates\": %d"                                                  FORMAT_STRING_NEWLINE
"    },"                                                                   FORMAT_STRING_NEWLINE
"    \"equipo\": {"                                                        FORMAT_STRING_NEWLINE
"        \"nombre\": \"%s FC\","                                           FORMAT_STRING_NEWLINE
"        \"escudo\": \"./imagenes/escudos/player/%s.png\","                FORMAT_STRING_NEWLINE
"        \"miembros\": {"                                                  FORMAT_STRING_NEWLINE
"            \"entrenador\": {%s},"                                        FORMAT_STRING_NEWLINE
"            \"futbolista\": ["                                            FORMAT_STRING_NEWLINE
"                {%s},"                                                    FORMAT_STRING_NEWLINE
"                {%s},"                                                    FORMAT_STRING_NEWLINE
"                {%s},"                                                    FORMAT_STRING_NEWLINE
"                {%s},"                                                    FORMAT_STRING_NEWLINE
"                {%s},"                                                    FORMAT_STRING_NEWLINE
"                {%s},"                                                    FORMAT_STRING_NEWLINE
"                {%s},"                                                    FORMAT_STRING_NEWLINE
"                {%s},"                                                    FORMAT_STRING_NEWLINE
"                {%s},"                                                    FORMAT_STRING_NEWLINE
"                {%s},"                                                    FORMAT_STRING_NEWLINE
"                {%s}"                                                     FORMAT_STRING_NEWLINE
"            ]"                                                            FORMAT_STRING_NEWLINE
"        }"                                                                FORMAT_STRING_NEWLINE
"    }"                                                                    FORMAT_STRING_NEWLINE
"}"                                                                        FORMAT_STRING_NEWLINE
"]"                                                                        FORMAT_STRING_NEWLINE
""                                                                         FORMAT_STRING_NEWLINE
;

#endif
