#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int main()
{
    int city[100] = {0}, bridge[100][100] = { {0} }, n_bridge[100] = {0};
    int n_city = 0, n_road = 0;
    int i = 0, j = 0;
    scanf("%d", &n_city);
    scanf("%d", &n_road);
    for(i = 0 ; i < n_road ; i++)
    {
        int a = 0 , b = 0;
        scanf("%d%d", &a, &b);
        bridge[a][ n_bridge[a] ] = b ;
        bridge[b][ n_bridge[b] ] = a ;
        n_bridge[a]++;
        n_bridge[b]++;
    }
    city[0] = -1;
    int tmp[100] = {0}, start = 0, end = 1, step = 1;
    while(start != end)
    {
        int n_remove = (end + 100 - start) % 100;
        for(i = 0 ; i < n_remove ; i++)
        {
            for(j = 0 ; j < n_bridge[ tmp[start] ] ; j++)
            {
                if(city [ bridge[ tmp[start] ][j] ] == 0)
                {
                    city[ bridge[ tmp[start] ][j] ] = step;
                    tmp[end] = bridge[ tmp[start] ][j];
                    end = (end + 1) % 100;
                }
            }
            start = (start + 1) % 100;
        }
        step++;
    }
    for(i = 1 ; i < n_city ; i++)
    {
        if(city[i] == 0) printf("infinity\n");
        else printf("%d\n", city[i]);
    }
    return 0;
}
