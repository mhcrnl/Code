#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int gcd(int a, int b)
{
    while(b!=0)
    {
        int c = b;
        b = a % b;
        a = c;
    }
    return a;
}

void calc(int input[30][30][3], int floor, int ratio[30][30][2], int N)
{
    int i = 0, gcd_tmp = 0;
    if(floor == N + 1)
    {
        for(i = 0 ; i <= N ; i++) printf("%d/%d\n", ratio[N + 1][i][0], ratio[N + 1][i][1]);
        return;
    }
    ratio[floor + 1][0][0] = ratio[floor][0][0] * input[floor][0][0];
    ratio[floor + 1][0][1] = ratio[floor][0][1] * input[floor][0][2];
    gcd_tmp = gcd(ratio[floor + 1][0][0], ratio[floor + 1][0][1]);
    ratio[floor + 1][0][0] /= gcd_tmp;
    ratio[floor + 1][0][1] /= gcd_tmp;
    for(i = 1 ; i < floor ; i++)
    {
        ratio[floor + 1][i][1] = ratio[floor][i - 1][1] * input[floor][i - 1][2] * ratio[floor][i][1] * input[floor][i][2];
        ratio[floor + 1][i][0] = ratio[floor][i - 1][0] * input[floor][i - 1][1] * ratio[floor][i][1] * input[floor][i][2];
        ratio[floor + 1][i][0] += ratio[floor][i - 1][1] * input[floor][i - 1][2] * ratio[floor][i][0] * input[floor][i][0];
        gcd_tmp = gcd(ratio[floor + 1][i][0], ratio[floor + 1][i][1]);
        ratio[floor + 1][i][0] /= gcd_tmp; 
        ratio[floor + 1][i][1] /= gcd_tmp;
    }
    ratio[floor + 1][floor][0] = ratio[floor][floor - 1][0] * input[floor][floor - 1][1];
    ratio[floor + 1][floor][1] = ratio[floor][floor - 1][1] * input[floor][floor - 1][2];
    gcd_tmp = gcd(ratio[floor + 1][floor][0], ratio[floor + 1][floor][1]);
    ratio[floor + 1][floor][0] /= gcd_tmp;
    ratio[floor + 1][floor][1] /= gcd_tmp;
    calc(input, floor + 1, ratio, N);
    return;
}

int main()
{
    int input[30][30][3] = { { {0} } }, ratio[30][30][2] = { { {0} } }, N = 0;
    int i = 0, j = 0;
    scanf("%d", &N);
    for(i = 1 ; i <= N ; i++)
    {
        for(j = 0 ; j < i ; j++)
        {
            int gcd_tmp = 0;
            scanf("%d %d", &input[i][j][0], &input[i][j][1]);
            gcd_tmp = gcd(input[i][j][0], input[i][j][1]);
            input[i][j][0] /= gcd_tmp;
            input[i][j][1] /= gcd_tmp;
            input[i][j][2] = input[i][j][0] + input[i][j][1];
        }
    }
    ratio[1][0][0] = 1;
    ratio[1][0][1] = 1;
    calc(input, 1, ratio, N);
    return 0;
}
