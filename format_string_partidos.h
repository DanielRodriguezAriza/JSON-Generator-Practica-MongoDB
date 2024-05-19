#ifndef FORMAT_STRING_PARTIDOS
#define FORMAT_STRING_PARTIDOS

#include "format_string.h"

static char const * const format_string_partidos =
""                                                                        FORMAT_STRING_NEWLINE
"{"                                                                       FORMAT_STRING_NEWLINE
"    \"estadio\": {%s}," /* (ENTRE 0 Y 19) */                             FORMAT_STRING_NEWLINE
"    \"duracion\": %d," /* (EN MINUTOS) */                                FORMAT_STRING_NEWLINE
"    \"fecha\": {"                                                        FORMAT_STRING_NEWLINE
"    },"                                                                  FORMAT_STRING_NEWLINE
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

/*
#ifndef FORMAT_STRING_PARTIDOS
#define FORMAT_STRING_PARTIDOS

#include "format_string.h"

static char const * const format_string_partidos = RAW_STRING(
{
	"estadio" : {%s},
	"duracion" : %d,
	"fecha" : {
		"day" : %d,
		"month" : %d,
		"year" : %d
	},
	"participantes": {
		"bots" : {
			"arbitro" : {%s},
			"comentarista_1" : {%s},
			"comentarista_2" : {%s}
		},
		"jugadores" : {
			"jugador_1" : %d,
			"jugador_2" : %d
		}
	},
	"resultado" : {
		"goles_jugador_1" : %d,
		"goles_jugador_2" : %d
	}
}
);

#endif

*/


/*
#ifndef FORMAT_STRING_PARTIDOS
#define FORMAT_STRING_PARTIDOS

#include "format_string.h"

static char const * const format_string_partidos =
RAW_STRING_LINE({                                    )
RAW_STRING_LINE(	"estadio" : {%s},                )
RAW_STRING_LINE(	"duracion" : %d,                 )
RAW_STRING_LINE(	"fecha" : {                      )
RAW_STRING_LINE(		"day" : %d,                  )
RAW_STRING_LINE(		"month" : %d,                )
RAW_STRING_LINE(		"year" : %d                  )
RAW_STRING_LINE(	},                               )
RAW_STRING_LINE(	"participantes": {               )
RAW_STRING_LINE(		"bots" : {                   )
RAW_STRING_LINE(			"arbitro" : {%s},        )
RAW_STRING_LINE(			"comentarista_1" : {%s}, )
RAW_STRING_LINE(			"comentarista_2" : {%s}  )
RAW_STRING_LINE(		},                           )
RAW_STRING_LINE(		"jugadores" : {              )
RAW_STRING_LINE(			"jugador_1" : %d,        )
RAW_STRING_LINE(			"jugador_2" : %d         )
RAW_STRING_LINE(		}                            )
RAW_STRING_LINE(	},                               )
RAW_STRING_LINE(	"resultado" : {                  )
RAW_STRING_LINE(		"goles_jugador_1" : %d,      )
RAW_STRING_LINE(		"goles_jugador_2" : %d       )
RAW_STRING_LINE(	}                                )
RAW_STRING_LINE(}                                    );

#endif

*/
