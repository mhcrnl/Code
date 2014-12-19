#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct ch_link
{
    char ch;
    struct ch_link *next;
}
CH_L;

void init_ch(CH_L *ch_l)
{
    ch_l->ch = 0;
    ch_l->next = NULL;
    return;
}

CH_L* insert(int n, char ch_input, CH_L *ch_l, int *total)
{
    CH_L *input;
    input = (CH_L*)malloc(sizeof(CH_L));
    init_ch(input);
    input->ch = ch_input;
    if(n == 1)
    {
        input->next = ch_l;
        *total += 1;
        return input;
    }
    else
    {
        int i = 0;
        CH_L *tmp = ch_l;
        for(i = 2 ; i < n ; i++) tmp = tmp->next;
        if(n != *total + 1) input->next = tmp->next;
        tmp->next = input;
        *total += 1;
    }
    return ch_l;
}

CH_L* delete(int n, CH_L *ch_l, int *total)
{
    CH_L *tmp = ch_l;
    if(n == 1) 
    {
        *total -= 1;
        if(*total == 0)
        {
            CH_L *new;
            new = (CH_L*)malloc(sizeof(CH_L));
            return new;
        }
        return tmp->next;
    }
    else
    {
        int i = 0;
        for(i = 2 ; i < n ; i++) tmp = tmp->next;
        CH_L *tmp_2 = tmp->next;
        if(n != *total) tmp->next = tmp->next->next;
        else tmp->next = NULL;
        free(tmp_2);
    }
    *total -= 1;
    return ch_l;
}

int find_the_longest(CH_L *ch_l, char output[50])
{
    if(ch_l->ch == 0 && ch_l->next == NULL)
    {
        output[0] = '\0';
        return 0;
    }
    CH_L *tmp;
    tmp = ch_l;
    char now = tmp->ch;
    int max_len = 0, flag = 0, len = 0, n = 0;
    while(1)
    {
        if(tmp->ch == now) len++;
        if(tmp->ch != now || tmp->next == NULL)
        {
            if(len == max_len) output[n++] = now;
            if(len > max_len)
            {
                n = 1;
                output[0] = now;
                max_len = len;
            }
            now = tmp->ch;
            len = 1;
        }
        if(tmp->next == NULL)
        {
            if(max_len == 1 && n != 1) output[n++] = now;
            output[n] = '\0';
            return max_len;
        }
        else tmp = tmp->next;
    }
}

int main()
{
    int n = 0, total = 0;
    char input[3][100];
    CH_L *ch_l;
    ch_l = (CH_L*)malloc(sizeof(CH_L));
    init_ch(ch_l);
    while(scanf("%s", input[0]) != EOF)
    {
        int i = 0;
        scanf("%s", input[1]);
        if(input[1][0] == 'l') n = 1;
        else if(input[1][0] == 'r') n = total;
        else n = atoi(input[1]);
        if(input[0][0] == 'i')
        {
            if(input[1][0] == 'r') n++;
            scanf("%s", input[2]);
            ch_l = insert(n, input[2][0], ch_l, &total);
        }
        else ch_l = delete(n, ch_l, &total);
    }
    char output[50];
    int max = find_the_longest(ch_l, output);
    int i = 0;
    for(i = 0 ; output[i] != '\0'; i++) if(output[i] != 0) printf("%c ", output[i]);    
    printf("%d\n", max);
    return 0;
}
