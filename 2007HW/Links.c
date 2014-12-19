#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct link_data
{
    char name[8192];
    int times;
}
L;

void add_link(char *s, L link[521], int *top)
{
    int i = 0;
    char name[8192];
    for(i = 6 ; i < strlen(s) ; i++)
    {
        if(s[i] == '\"') break;
        name[i - 6] = s[i];
    }
    name[i - 6] = '\0';
    for(i = 0 ; i < *top ; i++)
    {
        if( strcmp(link[i].name, name) == 0)
        {
            link[i].times++;
            break;
        }
    }
    if(i == *top)
    {
        strcpy(link[*top].name, name);
        link[*top].times = 1;
        *top = *top + 1;
    }
    return;
}

void sort_link(L link[521], int *top)
{
    int i = 0, j = 0, k = 0;
    for(i = 0 ; i < top[0] - 1 ; i++)
        for(j = i + 1 ; j < *top ; j++)
        {
            k = 0;
            while(link[i].name[k] == link[j].name[k]) k++;
            if(link[i].name[k] > link[j].name[k])
            {
                L tmp;
                tmp = link[i];
                link[i] = link[j];
                link[j] = tmp;
            }
        }
    return;
}

void print_link(L link[521], int *top)
{
    int i = 0;
    for(i = 0 ; i < *top ; i++) printf("%d %s\n", link[i].times, link[i].name);
    return;
}

int main()
{
    L link[521];
    int top = {0};
    char tmp[8192];
    while(gets(tmp) != 0)
    {
        char *s_1, *s_2;
        s_1 = strstr(tmp, "HREF=\""); 
        while(s_1 != NULL)
        {
            add_link(s_1, link, &top);
            s_1 = strstr(s_1+1, "HREF=\""); 
        }
        s_2 = strstr(tmp, "href=\""); 
        while(s_2 != NULL)
        {
            add_link(s_2, link, &top);
            s_2 = strstr(s_2+1, "href=\"");
        }
    }
    sort_link(link, &top);
    print_link(link, &top);
    return 0;
}
