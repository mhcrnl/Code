#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main()
{
    Time t;
    initTime(&t);
    addTime(&t, 14, 30, 2);
    printTime(&t);
    addTime(&t, 19, 32, 36);
    printTime(&t);
    setTime(&t, 2, 7, 12);
    printTime(&t);
    addTime(&t, 15, 5, 45);
    printTime(&t);
    setTime(&t, 15, 30, 21);
    printTime(&t);
    return 0;
}
