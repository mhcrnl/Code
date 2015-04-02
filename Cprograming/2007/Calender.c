#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int year = 0, month = 0, day = 0, n = 0;
    int i = 0;
    scanf("%d %d %d", &year, &month, &day);
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            n = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            n = 30;
            break;
        case 2:
            if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) n = 29;
            else n = 28;
            break;
    }
    if(month > 12 || month < 1 || day < 0 || day > 6) printf("invalid\n");
    else
    {
        printf(" Su Mo Tu We Th Fr Sa\n");
        printf("=====================\n");
        for(i = 0 ; i < day ; i++) printf("   ");
        for(i = 1 ; i <= n; i++)
        {
            printf("%3d", i);
            if((i + day) % 7 == 0) printf("\n");
        }
        if((i + day) % 7 != 1) printf("\n");
        printf("=====================\n");
    }
    return 0;
}
