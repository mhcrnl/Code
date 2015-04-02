#include <stdio.h>
#include <stdlib.h>

void try_case(int input[],int used[], int N, int now, int output[])
{
    int i = 0;
    if(now == N)
    {
        for(i = 0 ; i < N - 1 ; i++) printf("%d ", output[i]);
        if(i == N - 1) printf("%d\n", output[i]);
        return;
    }
    for(i = 0 ; i < N ; i++)
        if(used[i] == 0)
        {
           used[i] = 1;
           output[now] = input[i];
           try_case(input, used, N, now + 1, output);
           used[i] = 0;
        }
    return;
}

int main()
{
    int N = 0;
    scanf("%d", &N);
    int input[N], output[N], used[10] = {0};
    int i = 0, j = 0;
    for(i = 0 ; i < N ; i++) scanf("%d", &input[i]);
    for(i = 0 ; i < N - 1 ; i++)
        for(j = i + 1 ; j < N ; j++)
            if(input[i] > input[j])
            {
                int tmp = input[i];
                input[i] = input[j];
                input[j] = tmp;
            }
    try_case(input, used, N, 0, output);
    return 0;
}
