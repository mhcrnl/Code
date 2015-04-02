#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct val
{
    char name[10];
    int value;
}
Val;

typedef struct line_content
{
    int num;
    char content[10][10];
    int n_content;
}
Line;

Val v[200];
Line line[1000];
int n_v = 0, n_line = 0, if_flag = 0, next = 0;

int exe(int now, int flag);
int go(int now, int flag);
int pr(int now, int flag);
int do_if(int now, int flag);
int calc(int now, int flag);
void read_value();
void read_line();

void read_value()
{
    char input[1500];
    gets(input);
    char *name, *value, *tmp;
    name = strtok(input, " ");
    while(strcmp(name, "END") != 0)
    {
        tmp = strtok(NULL, " ");
        value = strtok(NULL, " ");
        strcpy( v[n_v].name, name);
        v[n_v].value = atoi(value);
        n_v++;
        name = strtok(NULL, " ");
    }
    return;
}

void read_line()
{
    char input[100];
    while(gets(input) != 0)
    {
        int n = 0;
        n_line++;
        char *tmp;
        line[n_line].num = n_line;
        tmp = strtok(input, " ");
        while(tmp != NULL)
        {
            strcpy(line[n_line].content[n], tmp);
            n++;
            tmp = strtok(NULL, " ");
        }
        line[n_line].n_content = n;
    }
    return;
}

int exe(int now, int flag)
{
    if_flag = 0;
    if( strcmp(line[now].content[flag], "STOP") == 0 ) return -1;
    else if( strcmp(line[now].content[flag], "GOTO") == 0 ) return go(now, flag + 1);
    else if( strcmp(line[now].content[flag], "PRINT") == 0 ) return pr(now, flag + 1);
    else if( strcmp(line[now].content[flag], "IF") == 0 ) return do_if(now, flag + 1);
    else return calc(now, flag);
}

int go(int now, int flag)
{
    return atoi(line[now].content[flag]);
}

int pr(int now, int flag)
{
    int i = 0;
    for(i = 0 ; i < n_v ; i++) if( strcmp(line[now].content[flag], v[i].name) == 0 ) break;
    printf("%d\n", v[i].value);
    return now + 1;
}

int do_if(int now, int flag)
{
    int value_1 = 0, value_2 = 0;
    int i = 0;
    for(i = 0 ; i < n_v ; i++) if( strcmp(line[now].content[flag], v[i].name) == 0 ) break;
    value_1 = v[i].value;
    for(i = 0 ; i < n_v ; i++) if( strcmp(line[now].content[flag + 2], v[i].name) == 0 ) break;
    value_2 = v[i].value;
    int t_f = 0;
    if( strcmp(line[now].content[flag + 1], "==") == 0 ) t_f = (value_1 == value_2);
    else if( strcmp(line[now].content[flag + 1], "!=") == 0 ) t_f = (value_1 != value_2);
    else if( strcmp(line[now].content[flag + 1], ">") == 0 ) t_f = (value_1 > value_2);
    else if( strcmp(line[now].content[flag + 1], ">=") == 0 ) t_f = (value_1 >= value_2);
    else if( strcmp(line[now].content[flag + 1], "<") == 0 ) t_f = (value_1 < value_2);
    else if( strcmp(line[now].content[flag + 1], "<=") == 0 ) t_f = (value_1 <= value_2);
    if(t_f == 0) return now + 1;
    if_flag = flag + 3;
    return now;
}

int calc(int now, int flag)
{
    int value_1 = 0, value_2 = 0;
    int i = 0;
    for(i = 0 ; i < n_v ; i++) if( strcmp(line[now].content[flag + 2], v[i].name) == 0 ) break;
    value_1 = v[i].value;
    for(i = 0 ; i < n_v ; i++) if( strcmp(line[now].content[flag + 4], v[i].name) == 0 ) break;
    value_2 = v[i].value;
    for(i = 0 ; i < n_v ; i++) if( strcmp(line[now].content[flag], v[i].name) == 0 ) break;
    if( strcmp(line[now].content[flag + 3], "+") == 0 ) v[i].value = value_1 + value_2;
    else if( strcmp(line[now].content[flag + 3], "-") == 0 ) v[i].value = value_1 - value_2;
    else if( strcmp(line[now].content[flag + 3], "*") == 0 ) v[i].value = value_1 * value_2;
    else if( strcmp(line[now].content[flag + 3], "/") == 0 ) v[i].value = value_1 / value_2;
    else if( strcmp(line[now].content[flag + 3], "%") == 0 ) v[i].value = value_1 % value_2;
    return now + 1;
}

int main()
{
    read_value();
    read_line();
    while(next != -1) next = exe(next, if_flag);
    return 0;
}