#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void choose(int *output, int n_out, int now, int N, int m, int *input, int *group, int want)
{
    if(n_out == want)
    {
        int i =0;
        for(i = 0 ; i < n_out ; i++)
        {
            printf("%d", output[i]);
            if(i == n_out - 1) printf("\n");
            else printf(" ");
        }
        return;
    }
    if(now == N) return;
    if(group[input[now] % m] != 0)
    {
        output[n_out] = input[now];
        group[input[now] % m] --;
        choose(output, n_out + 1, now + 1, N, m, input, group, want);
        group[input[now] % m] ++;
    }
    choose(output, n_out, now + 1, N, m, input, group, want);
    return;
}

int main()
{
    int N = 0, m = 0;
    int i = 0, j = 0;
    scanf("%d", &N);
    int input[N], output[N];
    for(i = 0 ; i < N ; i++) scanf("%d", &input[i]);
    for(i = 0 ; i < N - 1 ; i++)
    {
        for(j = i + 1 ; j < N ; j++)
        {
            if(input[i] > input[j])
            {
                int tmp = input[i];
                input[i] = input[j];
                input[j] = tmp;
            }
        }
    }
    scanf("%d", &m);
    int group[m], want = 0;
    for(i = 0 ; i < m ; i++)
    {
        scanf("%d", &group[i]);
        want += group[i];
    }
    choose(output, 0, 0, N, m, input, group, want);
    return 0;
}
