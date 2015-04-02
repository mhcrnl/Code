#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

typedef struct var
{
	char name[40];
	int value;
}
VAR;

typedef struct tree
{
	int value;
	char opr[2];
	struct tree *left;
	struct tree *right;	
}
TREE;

VAR v[100];
char expr[1000][40];
int n_v, n_expr;

void cut_exp(char *input)
{
	n_expr = 0;
	char *tmp;
	tmp = strtok(input, " ");
	while(tmp != NULL)
	{
		strcpy(expr[n_expr], tmp);
		n_expr++;
		tmp = strtok(NULL, " ");
	}
	return;
}

void get_var()
{
	n_v = 0;
	char tmp[2];
	while(scanf("%s %s %d", v[n_v].name, tmp, &v[n_v].value) != EOF)	n_v++;
	return;
}

TREE *calc(int now)
{
	TREE *t = (TREE*)malloc(sizeof(TREE));
	if(strcmp(expr[now], "(") == 0)
	{
		now++;
		strcpy(t->opr, expr[now++]);
		t->left = calc(now);
		int count = 0;
		while(1)
		{
			if(strcmp(expr[now], "(") == 0)	count++;
			else if(strcmp(expr[now], ")") == 0)	count--;
			now++;
			if(count == 0)	break;
		}
		t->right = calc(now);
		if(strcmp(t->opr, "+") == 0)	t->value = t->left->value + t->right->value;
		if(strcmp(t->opr, "-") == 0)	t->value = t->left->value - t->right->value;
		if(strcmp(t->opr, "*") == 0)	t->value = t->left->value * t->right->value;
		if(strcmp(t->opr, "/") == 0)	t->value = t->left->value / t->right->value;
		return t;
	}
	int i = 0;
	for(i = 0 ; i < n_v ; i++)	if(strcmp(v[i].name, expr[now]) == 0)	break;
	if(i == n_v)	t->value = atoi(expr[now]);
	else t->value = v[i].value;
	t->left = NULL;
	t->right = NULL;
	return t;
}

int main(void)
{
	char input[1500], equ[10];
	gets(input);
	cut_exp(input);
	get_var();
	int now = 0;
	TREE t = *calc(now);
	printf("%d\n", t.value);
	return 0;
}