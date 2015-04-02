#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flag = 0;

void try(int input[11][11], int table[11][11], int x, int y)
{
    if( x >= 2 && y >= 3)
    {
        int i = 0,j = 0, sum = 0;
        for(i = -1 ; i <= 1 ; i++)
            for(j = -1 ; j <= 1 ; j++)   sum += table[x - 1 + i][y - 2 + j];
        if(sum != input[x - 1][y - 2]) return;
    }
    if( x == 10 && y == 1)
    {
        int k = 0, i = 0, j = 0, sum = 0;
        for(k = 1 ; k <= 9 ; k++)
        {
            sum = 0;
            for(i = -1 ; i <= 1 ; i++)
                for(j = -1 ; j <= 0 ; j++)  sum += table[k + i][9 + j];
            if(sum != input[k][9]) return;
        }
        for(k = 1 ; k <= 9 ; k++)
        {
            sum = 0;
            for(i = -1 ; i <= 1 ; i++)
                for(j = -1 ; j <= 1 ; j++)  sum += table[k + i][8 + j];
            if(sum != input[k][8]) return;
        }
        for(k = 1 ; k <= 7 ; k++)
        {
            sum = 0;
            for(i = -1 ; i <= 0 ; i++)
                for(j = -1 ; j <= 1 ; j++)  sum += table[9 + i][k + j];
            if(sum != input[9][k]) return;
        }
        for(i = 1 ; i < 10 ; i++)
        {
            flag = 1;
            for(j = 1 ; j < 9 ; j++)   printf("%d ", table[i][j]);
            printf("%d\n", table[i][j]);
        }
        return;
    }
    table[x][y] = 0;
    try(input, table, x + (y + 1)/10, (y + 1)/10 + (y + 1) % 10);
    if(flag == 1) return;
    table[x][y] = 1;
    try(input, table, x + (y + 1)/10, (y + 1)/10 + (y + 1) % 10);
    table[x][y] = 0;
    return;
}

int main()
{
    int table[11][11] = { {0} }, input[11][11] = { {0} };
    int i = 0, j = 0;
    for(i = 1 ; i < 10 ; i++)
        for(j = 1 ; j < 10 ; j++) scanf("%d", &input[i][j]);
    try(input, table, 1, 1);
    if(flag == 0) printf("no solution\n");
    return 0;
}
