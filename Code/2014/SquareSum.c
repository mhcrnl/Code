#include <stdio.h>
#include <stdlib.h>

int square_sum(int n, int now)
{
    if(now > n) return 0;
    return ( now*now + square_sum(n, now + 1) );
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    printf( "%d\n", square_sum(n, 1) );
    return 0 ;
}
