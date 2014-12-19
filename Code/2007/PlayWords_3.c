#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct list_c
{
    char c;
    int len;
    struct list_c *next;
}
LIST_C;

void init_lc(LIST_C *lc)
{
    lc->c = '$';
    lc->len = 0;
    lc->next = NULL;
    return;
}

LIST_C* insert(LIST_C *lc, int place, char c, int len)
{
    if(place == 1 || lc->c == '$')
    {
        if(c == lc->c)
        {
            lc->len += len;
            return lc;
        }
        else
        {
            LIST_C *new;
            new = (LIST_C*)malloc(sizeof(LIST_C));
            init_lc(new);
            new->c = c;
            new->len = len;
            new->next = lc;
            return new;
        }
    }
    else if(place == -1)
    {
        LIST_C *tmp;
        tmp = lc;
        while(tmp->next->c != '$') tmp = tmp->next;
        if(c == tmp->c) tmp->len += len;
        else
        {
            LIST_C *new;
            new = (LIST_C*)malloc(sizeof(LIST_C));
            init_lc(new);
            new->c = c;
            new->len = len;
            new->next = tmp->next;
            tmp->next = new;
        }
        return lc;
    }
    else
    {
        LIST_C *tmp;
        tmp = lc;
        int sum = tmp->len;
        while(place > sum + 1)
        {
            tmp = tmp->next;
            sum += tmp->len;
        }
        if(place == sum + 1)
        {
            if(c == tmp->c) tmp->len += len;
            else if(c == tmp->next->c) tmp->next->len += len;
            else
            {
                LIST_C *new;
                new = (LIST_C*)malloc(sizeof(LIST_C));
                init_lc(new);
                new->c = c;
                new->len = len;
                new->next = tmp->next;
                tmp->next = new;
            }
        }
        else
        {
            if(c == tmp->c) tmp->len += len;
            else
            {
                tmp->len -= (sum - place + 1);
                LIST_C *new, *old;
                new = (LIST_C*)malloc(sizeof(LIST_C));
                old = (LIST_C*)malloc(sizeof(LIST_C));
                init_lc(new);
                init_lc(old);
                new->c = c;
                old->c = tmp->c;
                new->len = len;
                old->len = (sum - place + 1);
                old->next = tmp->next;
                tmp->next = new;
                new->next = old;
            }
        }
        return lc;
    }
}

void print(LIST_C *lc)
{
    LIST_C *tmp;
    tmp = lc;
    while(tmp->c != '$')
    {
        printf("%c %d ",tmp->c, tmp->len);
        tmp = tmp->next;
    }
    printf("$\n");
}

int main()
{
    LIST_C *lc;
    lc = (LIST_C*)malloc(sizeof(LIST_C));
    init_lc(lc);
    char cmd[10];
    while(scanf("%s", cmd) != EOF)
    {
        if( strcmp(cmd, "print") == 0 ) print(lc);
        else
        {
            char s_p[10], c[2];
            int len = 0, place = 0;
            scanf("%s%s%d", s_p, c, &len);
            if(s_p[0] == 'l') place = 1;
            else if(s_p[0] == 'r') place = -1;
            else place = atoi(s_p);
            lc = insert(lc, place, c[0], len);
        }
    }
    return 0;
}
