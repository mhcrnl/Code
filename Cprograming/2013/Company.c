#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    typedef struct employee
    {
        int id;
        char fn[32];
        char ln[32];
        int boss_id;
        int up[100];
        int top;
    }
    Emp;

    int n = 0, in = 0, i = 0, j = 0;
    scanf("%d", &n);
    Emp e[n];
    for(i = 0 ; i < n ; i++)
    {
        scanf("%d%s%s%d", &(e[i].id), e[i].fn, e[i].ln, &(e[i].boss_id));
        e[i].top = 0;
    }

    scanf("%d", &in);
    char input[in][2][2][32];
    for(i = 0 ; i < in ; i++)   scanf("%s%s%s%s", input[i][0][0], input[i][0][1], input[i][1][0], input[i][1][1]);

    for(i = 0 ; i < n ; i++)
    {
        int now = 0;
        now = e[i].boss_id;
        while(1)
        {
            for(j = 0 ; j < n ; j++)    if(now == e[j].id) break;
            e[i].up[e[i].top] = now;
            now = e[j].boss_id;
            e[i].top++;
            if(e[j].id == e[j].boss_id) break;
        }
    }
    
    for(i = 0 ; i < in ; i++)
    {
        int p1 = 0, p2 = 0, flag = 0;
        for(j = 0 ; j < n ; j++)
        {
            if(strcmp(e[j].fn, input[i][0][0]) == 0 && strcmp(e[j].ln, input[i][0][1]) == 0) p1 = j;
            if(strcmp(e[j].fn, input[i][1][0]) == 0 && strcmp(e[j].ln, input[i][1][1]) == 0) p2 = j;
        }
        for(j = 0 ; j < e[p2].top ; j++)
        {
            if(e[p1].id == e[p2].up[j])
            {
                flag = 1;
                printf("supervisor\n");
            }
        }
        for(j = 0 ; j < e[p1].top ; j++)
        {
            if(e[p2].id == e[p1].up[j])
            {
                flag = 1;
                printf("subordinate\n");
            }
        }
        if(flag == 0 && e[p1].up[ e[p1].top - 1 ] == e[p2].up[ e[p2].top - 1 ]) printf("colleague\n");
        else if(flag == 0)  printf("unrelated\n");
    }
    return 0;
}
