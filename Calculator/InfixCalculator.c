#include "InfixCalculator.h"
#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h" // ConvToRPNExp
#include "PostCalculator.h" // EvalRPNExp

int EvalInfixExp(char *exp)
{
    int len = strlen(exp);
    int ret;
    char *expcpy = (char*)malloc(len+1);
    strcpy(expcpy, exp);

    ConvToRPNExp(expcpy); // 후휘 표기법으로 변환
    ret = EvalRPNExp(expcpy); // 계산

    free(expcpy);
    return ret;
}


