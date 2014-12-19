#include <stdio.h>


void sort(int **key_table[], int *sorted_array[])
{
    int n = 0, n_k = 0;
    int i = 0, j = 0;
    while(key_table[n_k] != NULL)
    {
        int n_a = 0;
        while(key_table[n_k][n_a] != NULL)
        {
            sorted_array[n] = key_table[n_k][n_a];
            n++;
            n_a++;
        }
        n_k++;
    }
    for(i = 0 ; i < n - 1 ; i++)
        for(j = i + 1 ; j < n ; j++)
            if(*sorted_array[i] > *sorted_array[j])
            {
                int *tmp = sorted_array[i];
                sorted_array[i] = sorted_array[j];
                sorted_array[j] = tmp;
            }
    return;
}

int main()
{
    int i;
    int one = 1, two = 2, three = 3, four = 4, five = 5, six = 6;
    int *array1[] = {&two, &six, &one, NULL};
    int *array2[] = {&five, &three, NULL};
    int *array3[] = {&four, &one, NULL};
    int *array4[] = {&one, NULL};
    int **key_table[] = {array1, array2, array3, array4, NULL};
    int *sorted_array[8];

    sort(key_table, sorted_array);

    for (i = 0; i < 8; i++)
        printf("%d %d\n", i, *sorted_array[i]);

    return 0;
}
