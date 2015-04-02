#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int d[6] = {0}, x[4] = {0}, y[4] = {0};
    int i = 0, flag = 0;
    for(i = 0 ; i < 4 ; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
        if(x[i] > 1000 || x[i] < -1000) flag = 1;
        if(y[i] > 1000 || y[i] < -1000) flag = 1;
    }
    for(i = 0 ; i < 4 ; i++)
        d[i] = (x[i] - x[(i + 1) % 4]) * (x[i] - x[(i + 1) % 4]) + (y[i] - y[(i + 1) % 4]) * (y[i] - y[(i + 1) % 4]);
    d[4] = (x[2] - x[0]) * (x[2] - x[0]) + (y[2] - y[0]) * (y[2] - y[0]);
    d[5] = (x[3] - x[1]) * (x[3] - x[1]) + (y[3] - y[1]) * (y[3] - y[1]);
    if(flag == 1) printf("invalid\n");
    else if(d[0] == d[1] && d[0] == d[2] && d[0] == d[3] && d[4] == d[5] && d[4] == 2 * d[0]) printf("square\n");
    else if(d[0] == d[1] && d[0] == d[2] && d[0] == d[3]) printf("diamond\n");
    else if(d[0] == d[2] && d[1] == d[3] && d[4] == d[5] && d[4] == d[0] + d[1]) printf("rectangle\n");
    else if(d[0] == d[2] && d[1] == d[3]) printf("parallelogram\n");
    else printf("others\n");
    return 0;
}
