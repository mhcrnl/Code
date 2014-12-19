#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct tree
{
	int value;
	struct tree *left;
	struct tree *right;
}
TREE;

void HLHR(TREE *t);
void HRHL(TREE *t);
int get_value(char *input);
TREE *read_data(char *input);

void HLHR(TREE *t)
{
	printf("%d\n", t->value);
	if(t->left != NULL)	HRHL(t->left);
	printf("%d\n", t->value);
	if(t->right != NULL)	HRHL(t->right);
	return;
}

void HRHL(TREE *t)
{
	printf("%d\n", t->value);
	if(t->right != NULL)	HLHR(t->right);
	printf("%d\n", t->value);
	if(t->left != NULL)	HLHR(t->left);
	return;
}

int get_value(char *input)
{
	int digit = 0;
	char value[20];
	while(*(input + digit) >= 48 && *(input + digit) <= 57)	digit++;
	strncpy(value, input, digit);
	return atoi(value);
}

TREE *read_data(char *input)
{
	TREE *t = (TREE*)malloc(sizeof(TREE));
	if(*input >= 48 && *input <= 57)
	{
		t->value = get_value(input);
		t->left = NULL;
		t->right = NULL;
		return t;
	}
	t->left = read_data(++input);
	int count = 1;
	while(count != 0)
	{
		if(*input == '(')	count++;
		else if(*input == ',')	count--;
		input++;
	}
	t->right = read_data(input);
	t->value = t->left->value + t->right->value;
	return t;
}

int main(void)
{
	TREE t;
	char input[5000];
	gets(input);
	t = *read_data(input);
	HLHR(&t);
	return 0;
}