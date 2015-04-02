#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee
{
    char first_name[32];
    char last_name[32];
    struct employee *boss;
}
Employee;

int relation(Employee *employee1, Employee *employee2)
{
    int flag = 0;
    Employee *tmp[2];
    tmp[0] = employee1;
    while(tmp[0] != tmp[0]->boss)
    {
        if(strcmp(tmp[0]->boss->first_name, employee2->first_name)== 0 && strcmp(tmp[0]->boss->last_name, employee2->last_name) == 0)  flag = 1;
        tmp[0] = tmp[0]->boss;
    }
    tmp[1] = employee2;
    while(tmp[1] != tmp[1]->boss)
    {
        if(strcmp(tmp[1]->boss->first_name, employee1->first_name)== 0 && strcmp(tmp[1]->boss->last_name, employee1->last_name) == 0)  flag = 2;
        tmp[1] = tmp[1]->boss;
    }
    if(flag == 0 && tmp[0] == tmp[1])   flag = 3;
    else if(flag == 0)  flag = 4;
    return flag;
}

int main()
{
    int n = 0;
    int i = 0, j = 0;
    int count = 0;
    scanf("%d", &n);
    int input[n][2];
    Employee e[n];
    for(i = 0 ; i < n ; i++)
    {
        scanf("%d", &input[i][0]);
        scanf("%s", e[i].first_name);
        scanf("%s", e[i].last_name);
        scanf("%d", &input[i][1]);
    }
    for(i = 0 ; i < n ; i++)
        for(j = 0 ; j < n ; j++)    if(input[i][1] == input[j][0])  e[i].boss = &e[j];
    scanf("%d", &count);
    int output[count];
    char input_name[2][2][32];
    Employee e_tmp[2];
    for(i = 0 ; i < count ; i++)
    {
        for(j = 0 ; j < 2 ; j++)    scanf("%s%s", input_name[j][0], input_name[j][1]);
        for(j = 0 ; j < n ; j++)
        {
            if(strcmp(input_name[0][0], e[j].first_name) == 0 && strcmp(input_name[0][1], e[j].last_name) == 0) e_tmp[0] = e[j];
            if(strcmp(input_name[1][0], e[j].first_name) == 0 && strcmp(input_name[1][1], e[j].last_name) == 0) e_tmp[1] = e[j];
        }
        output[i] = relation(&e_tmp[0], &e_tmp[1]);
    }
    for(i = 0 ; i < count ; i++)    printf("%d\n", output[i]);
    return 0;
}
