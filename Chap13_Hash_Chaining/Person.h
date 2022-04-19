/*
 * hash slot에 담을 Person 객체
 */
#ifndef CHAP13_SIMPLEHASH_PERSON_H
#define CHAP13_SIMPLEHASH_PERSON_H

#define STR_LEN 50

typedef struct _person
{
    int ssn; // 주민등록번호, key
    char name[STR_LEN];
    char addr[STR_LEN];
} Person;

int GetSSN(Person *p);
void ShowPerInfo(Person *p);
Person *MakePersonData(int ssn, char *name, char *addr);

#endif //CHAP13_SIMPLEHASH_PERSON_H
