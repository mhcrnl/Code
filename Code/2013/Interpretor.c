#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct variable
{
    int val[500];
    char name[500][10];
    int top;
}
Var;

typedef struct input
{
    int num[500];
    char content[500][100];
    int top;
}
Line;

Line line;
Var var;

int exe(int, int);
int go(int, int);
int pr(int, int);
int doif(int ,int);
int calc(int, int);

int if_tmp = 0;

int exe (int now, int ch)
{
    if_tmp = 0;
    char tmp[100];
    int i = 0, j = 0, k = 0;
    for(i = ch ; i <= strlen(line.content[now]) ; i++)  if(line.content[now][i] == ' ') break;
    for(j = i + 1 ; j <= strlen(line.content[now]) ; j++)  if(line.content[now][j] == ' ' || line.content[now][j] == '\0' ) break;
    for(k = i + 1 ; k < j ; k++) tmp[k -(i + 1)] = line.content[now][k];
    tmp[j - (i + 1)] = '\0';
    if(strcmp(tmp, "STOP") == 0) return -1;
    else if(strcmp(tmp, "GOTO") == 0) return go(now, j);
    else if(strcmp(tmp, "PRINT") == 0)  return pr(now, j);
    else if(strcmp(tmp, "IF") == 0) return doif(now, j);
    else  return calc(now, ch);
}

int go(int now, int ch)
{
    int i = 0, j = 0, k = 0, n = 0;
    char tmp[100];
    for(i = ch ; i <= strlen(line.content[now]) ; i++)  if(line.content[now][i] == ' ') break;
    for(j = i + 1 ; j <= strlen(line.content[now]) ; j++)  if(line.content[now][j] == ' ' || line.content[now][j] == '\0' ) break;
    for(k = i + 1 ; k < j ; k++) tmp[k -(i + 1)] = line.content[now][k];
    tmp[j - (i + 1)] = '\0';
    n = atoi(tmp);
    for(i = 0 ; i < line.top ; i++) if(n == line.num[i])  break;
    return i;
}

int pr(int now, int ch)
{
    int i = 0, j = 0, k = 0;
    char tmp[100];
    for(i = ch ; i <= strlen(line.content[now]) ; i++)  if(line.content[now][i] == ' ') break;
    for(j = i + 1 ; j <= strlen(line.content[now]) ; j++)  if(line.content[now][j] == ' ' || line.content[now][j] == '\0' ) break;
    for(k = i + 1 ; k < j ; k++) tmp[k -(i + 1)] = line.content[now][k];
    tmp[j - (i + 1)] = '\0';
    for(i = 0 ; i < var.top ; i++) if(strcmp(tmp, var.name[i]) == 0)  break;
    printf("%d\n", var.val[i]);
    return now + 1;
}

int doif(int now, int ch)
{
    int i = 0, j = 0, k = 0, t = 0, tmp_val[2] = {0};
    char tmp[3][100];
    for(t = 0 ; t < 3 ; t++)
    {
        for(i = ch ; i <= strlen(line.content[now]) ; i++)  if(line.content[now][i] == ' ') break;
        for(j = i + 1 ; j <= strlen(line.content[now]) ; j++)  if(line.content[now][j] == ' ' || line.content[now][j] == '\0' ) break;
        for(k = i + 1 ; k < j ; k++) tmp[t][k -(i + 1)] = line.content[now][k];
        tmp[t][j - (i + 1)] = '\0';
        ch = j;
    }
    for(i = 0 ; i < var.top ; i++)  if(strcmp(tmp[0], var.name[i]) == 0) break;
    tmp_val[0] = var.val[i];
    for(i = 0 ; i < var.top ; i++)  if(strcmp(tmp[2], var.name[i]) == 0) break;
    if(i == var.top) tmp_val[1] = atoi(tmp[2]);
    else  tmp_val[1] = var.val[i];
    int flag = 0;
    if(strcmp(tmp[1], "==") == 0)  flag = (tmp_val[0] == tmp_val[1]);
    else if(strcmp(tmp[1], "!=") == 0) flag = (tmp_val[0] != tmp_val[1]);
    else if(strcmp(tmp[1], ">") == 0) flag = (tmp_val[0] > tmp_val[1]);
    else if(strcmp(tmp[1], ">=") == 0) flag = (tmp_val[0] >= tmp_val[1]);
    else if(strcmp(tmp[1], "<") == 0) flag = (tmp_val[0] < tmp_val[1]);
    else if(strcmp(tmp[1], "<=") == 0) flag = (tmp_val[0] <= tmp_val[1]);
    if(flag == 0) return now + 1;
    else
    {
        if_tmp = j;
        return now;
    }
}

int calc(int now, int ch)
{
    int i = 0, j = 0, k = 0, t = 0, tmp_val[2] = {0};
    char tmp[10][100];
    while(ch != strlen(line.content[now]))
    {
        for(i = ch ; i <= strlen(line.content[now]) ; i++)  if(line.content[now][i] == ' ') break;
        for(j = i + 1 ; j <= strlen(line.content[now]) ; j++)  if(line.content[now][j] == ' ' || line.content[now][j] == '\0' ) break;
        for(k = i + 1 ; k < j ; k++) tmp[t][k -(i + 1)] = line.content[now][k];
        tmp[t][j - (i + 1)] = '\0';
        ch = j;
        t++;
    }
    switch(t)
    {
        case 3:
            for(k = 0 ; k < var.top ; k++)  if(strcmp(tmp[0], var.name[k]) == 0) break;
            if(k == var.top)
            {
                strcpy(var.name[k], tmp[0]);
                var.top++;
            }
            for(i = 0 ; i < var.top ; i++)  if(strcmp(tmp[2], var.name[i]) == 0) break;
            if(i == var.top) tmp_val[0] = atoi(tmp[2]);
            else  tmp_val[0] = var.val[i];
            var.val[k] = tmp_val[0];
            break;
        case 5:
            for(k = 0 ; k < var.top ; k++)  if(strcmp(tmp[0], var.name[k]) == 0) break;
            if(k == var.top)
            {
                strcpy(var.name[k], tmp[0]);
                var.top++;
            }
            for(i = 0 ; i < var.top ; i++)  if(strcmp(tmp[2], var.name[i]) == 0) break;
            if(i == var.top) tmp_val[0] = atoi(tmp[2]);
            else  tmp_val[0] = var.val[i];
            for(i = 0 ; i < var.top ; i++)  if(strcmp(tmp[4], var.name[i]) == 0) break;
            if(i == var.top) tmp_val[1] = atoi(tmp[4]);
            else  tmp_val[1] = var.val[i];
            if(strcmp(tmp[3], "+") == 0) var.val[k] = tmp_val[0] + tmp_val[1];
            else if(strcmp(tmp[3], "-") == 0) var.val[k] = tmp_val[0] - tmp_val[1];
            else if(strcmp(tmp[3], "*") == 0) var.val[k] = tmp_val[0] * tmp_val[1];
            else if(strcmp(tmp[3], "/") == 0) var.val[k] = tmp_val[0] / tmp_val[1];
            else if(strcmp(tmp[3], "%") == 0) var.val[k] = tmp_val[0] % tmp_val[1];
            break;
    }
    return now + 1;
}

int main()
{
    var.top = 0;
    line.top = 0;
    if_tmp = 0;
    while(scanf("%d", &line.num[line.top]) != EOF)
    {
        gets(line.content[line.top]);
        line.top++;
    }
    int next = 0;
    while (next != -1)  next = exe(next, if_tmp);
    return 0;
}
