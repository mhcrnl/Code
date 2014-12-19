#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    long long int shelf = 0;
    int new = 0;
    int i = 0;
    while(scanf("%d", &new) != EOF)
    {
        for(i = 7 ; i >= 0 ; i--)
            if((255 & (shelf >> (8 * i))) == new) break;
        if(i == -1) shelf = (shelf << 8) | new;
        else
        {
            int j = 0;
            long long int tmp = 255, right = 0, left = 0;
            for(j = 0 ; j < i ; j++)
            {
                right += tmp;
                tmp *= 256;
            }
            left = ((~right) << 8) & shelf;
            right = (right & shelf) << 8;
            shelf = (left | right) | new;       
        }
    }
    for(i = 7 ; i >= 0 ; i--) printf("%lld ", 255 & (shelf >> (8 * i)));
    printf("\n");
    return 0;
}
