#include <stdio.h>
#include <stdlib.h>

int main()
{
    int bonus[7] = {0, 10, 100, 1000, 10000, 100000, 1000000};
    int N = 0;
    scanf("%d", &N);
    int ticket[N][6], table_win[43] = {0}, total = 0;
    int i = 0, j = 0;
    for(i = 0 ; i < N ; i++)
        for(j = 0 ; j < 6 ; j++) scanf("%d", &ticket[i][j]);
    for(i = 0 ; i < 6 ; i++)
    {
        int tmp = 0;
        scanf("%d", &tmp);
        table_win[tmp] = 1;
    }
    for(i = 0 ; i < N ; i++)
    {
        int bonus_type = 0;
        for(j = 0 ; j < 6 ; j++) bonus_type += table_win[ ticket[i][j] ];
        total += bonus[bonus_type];
    }
    printf("Wow! I've won %d dollars.\n", total);
    return 0;
}
