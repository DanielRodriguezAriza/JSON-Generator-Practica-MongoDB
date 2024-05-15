#ifndef OID_H
#define OID_H

#include "utils.h"

typedef char const *oid;

#include "oids_arbitros.h"
#include "oids_comentaristas.h"
#include "oids_entrenadores.h"
#include "oids_estadios.h"
#include "oids_futbolistas.h"

#define GET_RANDOM_OID(name, length) name[get_random_int(0, length - 1)];

#endif
