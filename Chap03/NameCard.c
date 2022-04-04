#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

NameCard *MakeNameCard(char *name, char *phone)
{
    NameCard *cpos = (NameCard*)malloc(sizeof(NameCard));
    strcpy(cpos->name, name);
    strcpy(cpos->phone, phone);
    return cpos;
}

void ShowNameCardInfo(NameCard *pcard)
{
    printf("name is %s\n", pcard->name);
    printf("phone number is %s\n\n", pcard->phone);
}

int NameCompare(NameCard *pcard, char *name)
{
    return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard *pcard, char *phone)
{
    strcpy(pcard->phone, phone);
}