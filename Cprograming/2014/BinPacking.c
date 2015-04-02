#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int choice[6][3] = { {0, 2, 1}, {0, 1, 2}, {2, 0, 1}, {2, 1, 0}, {1, 0, 2}, {1, 2, 0} };
    char answer_type[6][4] = { "BCG", "BGC", "CBG", "CGB", "GBC", "GCB" };
    while(1)
    {
        char answer[4];
        int bin[3][3] = { {0} };
        int min = 0, sum = 0;
        int i = 0, j = 0;
        for(i = 0 ; i < 3 ; i++)
            if( scanf("%d%d%d", &bin[i][0], &bin[i][1], &bin[i][2]) == EOF ) break;
        if(i != 3) break;
        for(i = 0 ; i < 3 ; i++)
            for(j = 0 ; j < 3 ; j++) sum += bin[i][j];
       min = sum;
       for(i = 0 ; i < 6 ; i++)
       {
           int tmp = 0;
           for(j = 0 ; j < 3 ; j++) tmp+= bin[j][ choice[i][j] ];
           if((sum - tmp) < min)
           {
               min = (sum - tmp);
               strcpy(answer, answer_type[i]);
           }
       }
       printf("%s %d\n", answer, min);
    }
    return 0;
}
