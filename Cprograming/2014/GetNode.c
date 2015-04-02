#include "node.h"
#include <stdio.h>
#include <stdlib.h>

struct node *getNode(struct node *head, unsigned int i)
{
	int total = 1;
	int j = 0;
	struct node *tmp = head;
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
		total++;
	}
	if(i >= total) return NULL;
	tmp = head;
	for(j = 0 ; j < total - i - 1 ; j++) tmp = tmp->next;
	return tmp;
}
