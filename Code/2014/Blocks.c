#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct block
{
    int num;
    struct block *next;
}
BLOCK;

void init(BLOCK *list_b)
{
    BLOCK *end;
    end = (BLOCK*)malloc(sizeof(BLOCK));
    end->num = -1;
    end->next = NULL;
    list_b->num = -1;
    list_b->next = end;
    return;
}

void set_num(BLOCK *list_b, int num)
{
    BLOCK *new;
    new = (BLOCK*)malloc(sizeof(BLOCK));
    new->num = num;
    new->next = list_b->next;
    list_b->next = new;
    return;
}

void add_num(BLOCK *list_b, int num)
{
    BLOCK *new, *tmp;
    new = (BLOCK*)malloc(sizeof(BLOCK));
    new->num = num;
    tmp = list_b;
    while(tmp->next->num != -1) tmp = tmp->next;
    new->next = tmp->next;
    tmp->next = new;
    return;
}

int remove_next(BLOCK *list_b)
{
    BLOCK *tmp;
    tmp = list_b->next;
    list_b->next = list_b->next->next;
    int num = tmp->num;
    free(tmp);
    return num;
}

void move_onto(BLOCK *list_b[], BLOCK *l_a, BLOCK *l_b)
{
    while(l_b->next->num != -1)
    {
        int num = 0;
        num = remove_next(l_b);
        set_num(list_b[num], num);
    }
    add_num(l_b, l_a->next->num);
    remove_next(l_a);
    while(l_a->next->num != -1)
    {
        int num = 0;
        num = remove_next(l_a);
        set_num(list_b[num], num);
    }
    return;
}

void move_over(BLOCK *list_b[], BLOCK *l_a, BLOCK *l_b)
{
    add_num(l_b, l_a->next->num);
    remove_next(l_a);
    while(l_a->next->num != -1)
    {
        int num = 0;
        num = remove_next(l_a);
        set_num(list_b[num], num);
    }
    return;
}

void pile_onto(BLOCK *list_b[], BLOCK *l_a, BLOCK *l_b)
{
    while(l_b->next->num != -1)
    {
        int num = 0;
        num = remove_next(l_b);
        set_num(list_b[num], num);
    }
    add_num(l_b, l_a->next->num);
    remove_next(l_a);
    while(l_a->next->num != -1)
    {
        int num = 0;
        num = remove_next(l_a);
        add_num(l_b, num);
    }
    return;
}

void pile_over(BLOCK *list_b[], BLOCK *l_a, BLOCK *l_b)
{
     while(l_a->next->num != -1)
    {
        int num = 0;
        num = remove_next(l_a);
        add_num(l_b, num);
    }
    return;
}

int do_cmd(BLOCK *list_b[], int n)
{
    int a = 0, b = 0;
    char cmd[2][5];
    scanf("%s", cmd[0]);
    if( strcmp(cmd[0], "quit") == 0 ) return -1;
    scanf("%d %s %d", &a, cmd[1], &b);
    BLOCK *l_a, *l_b;
    int i = 0, flag = 0;
    for(i = 0 ; i < n ; i++)
    {
        int flag_ab = 0;
        BLOCK *tmp;
        tmp = list_b[i];
        while(tmp->next->num != -1)
        {
            if(tmp->next->num == a)
            {
                l_a = tmp;
                flag_ab++;
                flag++;
            }
            if(tmp->next->num == b)
            {
                l_b = tmp->next;
                flag_ab++;
                flag++;
            }
            tmp = tmp->next;
        }
        if(flag_ab == 2) return 1;
        if(flag == 2) break;
    }
    if( strcmp(cmd[0],"move") == 0 && strcmp(cmd[1],"onto") == 0) move_onto(list_b, l_a, l_b);
    else if( strcmp(cmd[0],"move") == 0 && strcmp(cmd[1],"over") == 0) move_over(list_b, l_a, l_b);
    else if( strcmp(cmd[0],"pile") == 0 && strcmp(cmd[1],"onto") == 0) pile_onto(list_b, l_a, l_b);
    else if( strcmp(cmd[0],"pile") == 0 && strcmp(cmd[1],"over") == 0) pile_over(list_b, l_a, l_b);
    return 1;
}

void print(BLOCK *list_b[], int n)
{
    int i = 0;
    for(i = 0 ; i < n ; i++)
    {
        printf("%d:", i);
        BLOCK *tmp;
        tmp = list_b[i];
        while(tmp->next->num != -1)
        {
            printf(" %d", tmp->next->num);
            tmp = tmp->next;
        }
        printf("\n");
    }
    return;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    BLOCK *list_b[n];
    int i = 0;
    for(i = 0 ; i < n ; i++)
    {
        list_b[i] = (BLOCK*)malloc(sizeof(BLOCK));
        init(list_b[i]);
        set_num(list_b[i], i);
    }
    int next = 1;
    while(next != -1) next = do_cmd(list_b, n);
    print(list_b, n);
    return 0;
}
