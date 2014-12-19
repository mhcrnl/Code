#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void prepare_array(int buffer[], int *array[], int row, int column[])
{
    int i = 0;
    for(i = 0 ; i < row ; i++)
    {
        array[i] = buffer;
        buffer += column[i];
    }
    return;
}

int main()
{
    int i = 0, j = 0, n = 0;
    int row = 4;
    int column[4] = {10, 20, 30, 10};
    int *array[50];
    int buffer[10000];
    prepare_array(buffer, array, row, column);
    for (i = 0; i < 4; i++)
        for (j = 0; j < column[i]; j++)
        {
            array[i][j] = i * 100 + j;
            printf("array[%d][%d] = %d\n", i, j, array[i][j]);
            printf("buffer[%d] = %d\n", n, buffer[n]);
            n++;
        }
    return 0;
}
