#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table.h"

int MyHashFunc(int k)
{
    return k % 100;
}

int main()
{
    Table myTbl;
    Person *np;
    Person *sp;
    Person *rp;

    TBLInit(&myTbl, MyHashFunc);

    // data input
    np = MakePersonData(900254, "LEE", "Seoul");
    TBLInsert(&myTbl, GetSSN(np), np);

    np = MakePersonData(900139, "KIM", "Jeju");
    TBLInsert(&myTbl, GetSSN(np), np);

    np = MakePersonData(900827, "HAN", "Kangwon");
    TBLInsert(&myTbl, GetSSN(np), np);

    // data search
    sp = TBLSearch(&myTbl, 900254);
    if(sp != NULL) ShowPerInfo(sp);

    sp = TBLSearch(&myTbl, 900139);
    if(sp != NULL) ShowPerInfo(sp);

    sp = TBLSearch(&myTbl, 900827);
    if(sp != NULL) ShowPerInfo(sp);

    // data deletion
    rp = TBLDelete(&myTbl, 900254);
    if(rp != NULL) free(rp);

    rp = TBLDelete(&myTbl, 900139);
    if(rp != NULL) free(rp);

    rp = TBLDelete(&myTbl, 900827);
    if(rp != NULL) free(rp);
}