#include <stdio.h>
#include <stdlib.h>

int mul_ways(char table[][400][2], int N, int M, int i, int j)
{
    int l = 1, r = 1, t = 1, b = 1;
    if(i + 1 >= N || table[i + 1][j][0] == '0') b = 0;
    if(i - 1 < 0 || table[i - 1][j][0] == '0') t = 0;
    if(j + 1 >= M || table[i][j + 1][0] == '0') r = 0;
    if(j - 1 < 0 || table[i][j - 1][0] == '0') l = 0;
    return (l + r + t + b);
}

void calc_area(char table[][400][2], int N, int M, int i, int j, int area[500], int count)
{
    area[count]++;
    table[i][j][0] = '0';
    while(mul_ways(table, N, M, i, j) == 1)
    {
        if(i - 1 >= 0 && table[i - 1][j][0] == '1') i--;
        else if(j - 1 >= 0 && table[i][j - 1][0] == '1') j--;
        else if(j + 1 < M && table[i][j + 1][0] == '1') j++;
        else if(i + 1 < N && table[i + 1][j][0] == '1') i++;
        area[count]++;
        table[i][j][0] = '0';
    }
    if(mul_ways(table, N, M, i, j) > 1)
    {
        if(i - 1 >= 0 && table[i - 1][j][0] == '1')
            calc_area(table, N, M, i - 1, j, area, count);
        if(j - 1 >= 0 && table[i][j - 1][0] == '1')
            calc_area(table, N, M, i, j - 1, area, count);
        if(j + 1 < M && table[i][j + 1][0] == '1')
            calc_area(table, N, M, i, j + 1, area, count);
        if(i + 1 < N && table[i + 1][j][0] == '1')
            calc_area(table, N, M, i + 1, j, area, count);
    }
    return;
}

int main()
{
    int N = 0, M = 0, count = 0;
    scanf("%d %d", &N, &M);
    char table[400][400][2];
    int i = 0, j = 0;
    int area[100000] = {0};
    for(i = 0 ; i < N ; i++)
        for(j =  0 ; j < M ; j++)
            scanf("%s", table[i][j]);
    for(i = 0 ; i < N ; i++)
        for(j = 0 ; j < M ; j++)
            if(table[i][j][0] == '1')
            {
                calc_area(table, N, M, i, j, area, count);
                count++;
            }
    for(i = 0 ; i < count - 1 ; i++)
        for(j = i + 1 ; j < count ; j++)
            if(area[i] < area[j])
            {
                int tmp = area[i];
                area[i] = area[j];
                area[j] = tmp;
            }
    for(i = 0 ; i < count ; i++) printf("%d\n", area[i]);
    return 0;
}
