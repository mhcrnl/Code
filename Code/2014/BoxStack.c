#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp(const void *a, const void *b)
{
    if( *(int*)a > *(int*)b ) return 1;
    return 0;
}

int cmp_2(const void *a, const void *b)
{
    int i = 0;
    while( ((int*)a)[i] == ((int*)b)[i] ) i++;
    if( ((int*)a)[i] > ((int*)b)[i]) return 1;
    return 0;
}

int bigger(int box_a[], int box_b[], int d)
{
    int i = 0;
    for(i = 0 ; i < d ; i++)
        if(box_a[i] <= box_b[i]) break;
    if(i == d) return 1;
    return 0;
}

void copylist(int list_a[], int list_b[], int n_list)
{
    int i = 0;
    for(i = 0 ; i < n_list ; i++)
        list_a[i]  = list_b[i];
    return;
}

int main()
{
    int n = 0, d = 0;
    while( scanf("%d%d", &n, &d) != EOF )
    {
        int i = 0, j = 0;
        int max_len = 0, max_index = 0;
        int box[n][d + 1], list[n][n], n_list[n];
        for(i = 0 ; i < n ; i++) n_list[i] = 1;
        for(i = 0 ; i < n ; i++)
        {
            for(j = 0 ; j < d ; j++)
                scanf("%d", &box[i][j]);
            qsort(box[i], d, sizeof(int), cmp);
            box[i][d] = i + 1;
        }
        qsort(box, n, sizeof(box[0]), cmp_2);        
        for(i = 0 ; i < n ; i++) list[i][0] = box[i][d];
        for(i = 1 ; i < n ; i++)
        {
            for(j = i - 1 ; j >= 0 ; j--)
            {
                if( bigger(box[i], box[j], d) == 1 && n_list[i] <= n_list[j] ) 
                {
                    copylist(list[i], list[j], n_list[j]);
                    n_list[i] = n_list[j] + 1;
                    list[i][ n_list[i] - 1 ] = box[i][d];
                }
            }
            if(n_list[i] > max_len)
            {
                max_index = i;
                max_len = n_list[i];
            }
        }
        printf("%d\n", max_len);
        for(i = 0 ; i < max_len ; i++)
        {
            printf("%d", list[max_index][i]);
            if(i == max_len - 1) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
