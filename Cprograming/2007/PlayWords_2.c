#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert(char *s, int *n_s)
{
    char place[10], input[2];
    int num = 0, p = 0;
    scanf("%s", place);
    scanf("%s", input);
    scanf("%d", &num);
    if(place[0] == 'l') p = 0;
    else if(place[0] == 'r') p = *n_s;
    else p = atoi(place) - 1;
    char new[100000];
    if(p != 0) strncpy(new, s, p);
    int i = 0;
    for(i = 0 ; i < num ; i++) new[p + i] = input[0];
    new[p + num] = '\0';
    strcat(new, s + p);
    strcpy(s, new);
    *n_s += num;
    return;
}

void print(char *s, int n_s)
{
    char now = s[0];
    int count = 1;
    int i = 0;
    while(i < n_s)
    {
        i++;
        if(s[i] == now) count++;
        else
        {
            printf("%c %d ", now, count);
            now = s[i];
            count = 1;
        }
    }
    printf("$\n");
}

int main()
{
    char s[100000] = "$";
    int n_s = 0;
    char cmd[10];
    while(scanf("%s", cmd) != EOF)
    {
        if( strcmp(cmd, "print") == 0 ) print(s, n_s);
        else insert(s, &n_s);
    }
    return 0;
}
