/*
 * hash slot
 */

#ifndef CHAP13_SIMPLEHASH_SLOT_H
#define CHAP13_SIMPLEHASH_SLOT_H

#include "Person.h"

typedef int Key; // Person ssn
typedef Person * Value;

//enum SlotStatus {EMPTY, DELETED, INUSE};

typedef struct _slot
{
    Key key;
    Value val;
} Slot;

#endif //CHAP13_SIMPLEHASH_SLOT_H

