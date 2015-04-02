#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void fill_array(int *ptr[], int n)
{
    int i = 0, j = 0;
    int *tmp;
    for(i = 0 ; i < n ; i++) *ptr[i] = i;
    for(i = 0 ; i < n - 1 ; i++)
    {
        for(j = i + 1 ; j < n ; j++)
        {
            if(ptr[i] > ptr[j])
            {
                tmp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = tmp;
            }
        }
    }
    for(i = 0 ; i < n - 1 ; i++)
        for( tmp = ptr[i] + 1 ; tmp < ptr[i + 1] ; tmp++) *tmp = *ptr[i] + *ptr[i + 1];
    return;
}
int main()
{
    int test[100];
    int *ptr[4];
    ptr[0] = &test[5];
    ptr[1] = &test[10];
    ptr[2] = &test[7];
    ptr[3] = &test[13];
    fill_array(ptr, 4);
    int i = 0;
    for(i = 5; i < 14 ; i ++) printf("%d\n", test[i]);
    return 0;
}
