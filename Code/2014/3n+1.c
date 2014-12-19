#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int input[10000][2] = { {0} }, output[10000] = {0}, n = 0;
    int i = 0, j = 0;
    while(scanf("%d %d", &input[n][0], &input[n][1]) != EOF)    n++;
    for(i = 0 ; i < n ; i ++)
    {
        for(j = input[i][0] ; j <= input[i][1] ; j ++)
        {
            int count = 1, tmp = j;
            while(tmp != 1)
            {
                if(tmp % 2 == 1) tmp = tmp * 3 + 1;
                else tmp = tmp / 2;
                count ++;
            }
            if(count > output[i]) output[i] = count;
        }
    }
    for(i = 0 ; i < n ; i++)
    {
        printf("%d %d %d\n", input[i][0], input[i][1], output[i]);
    }
    return 0;
}
