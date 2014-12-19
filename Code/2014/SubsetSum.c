#include <stdio.h>
#include <stdlib.h>

int try_sum(int input, int ele[], int n, int now)
{
    if(input < 0) return 0;
    if(input == 0) return 1;
    if(now == n) return 0;
    return ( try_sum(input - ele[now], ele, n, now + 1) + try_sum(input, ele, n, now + 1) );
}

int main()
{
    int n = 0, input = 0;
    scanf("%d", &n);
    int ele[n];
    int i = 0;
    for(i = 0 ; i < n ; i++) scanf("%d", &ele[i]);
    while( scanf("%d", &input) != EOF ) printf( "%d\n", try_sum(input, ele, n, 0) );
    return 0;
}
