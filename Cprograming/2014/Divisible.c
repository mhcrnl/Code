#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int d_2(char *input)
{
    int n = strlen(input);
    if(input[n - 1] % 2 == 0) return 1;
    else return 0;
}

int d_3(char *input)
{
    int n = strlen(input), sum = 0;
    int i = 0;
    for(i = 0 ; i < n ; i++) sum += (input[i] - 48);
    if(sum % 3 == 0) return 1;
    else return 0;
}

int d_5(char *input)
{
    int n = strlen(input);
    if(input[n - 1] == 48 || input[n - 1] == 53) return 1;
    else return 0;
}

int d_11(char *input)
{
    int n = strlen(input), sum[2] = {0};
    int i = 0;
    for(i = 0 ; i < n ; i++) sum[i % 2] += (input[i] - 48);
    if((sum[0] - sum[1]) % 11 == 0) return 1;
    else return 0;
}

int main()
{
    char input[1500];
    while(1)
    {
        scanf("%s", input);
        if(strcmp(input, "-1") == 0) break;
        if(d_2(input) == 1) printf("yes ");
        else printf("no ");
        if(d_3(input) == 1) printf("yes ");
        else printf("no ");
        if(d_5(input) == 1) printf("yes ");
        else printf("no ");
        if(d_11(input) == 1) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
