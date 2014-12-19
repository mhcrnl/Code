#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 0, M = 0, F = 0;
    scanf("%d %d %d", &N, &M, &F);
    int x = 1 , y = 1, d = 0;
    int table[M + 2][N + 2], dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    int i = 0, j = 0;
    for(i = 0 ; i < M + 2 ; i++)
        for(j = 0 ; j < N + 2 ; j++)
        {
            if(i == 0 || j == 0 || i == M + 1 || j == N + 1) table[i][j] = 1;
            else table[i][j] = 0;
        }
    while(1)
    {
        table[x][y] = 1;
        if( table[x + 1][y] + table[x - 1][y] + table[x][y + 1] + table[x][y - 1] == 4 || F == 0) break;
        if( table[ x + dir[d][0] ][ y + dir[d][1] ] == 1 ) d = (d + 1) % 4;
        x += dir[d][0];
        y += dir[d][1];
        F--;
    }
    printf("%d %d\n", x - 1, y - 1);
    return 0;
}
