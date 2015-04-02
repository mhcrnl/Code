#include <stdio.h>
#include <stdlib.h>
#include <node.h>

struct node *merge(struct node *list1, struct node *list2)
{
	if(list1->value > list2->value)
	{
		struct node* tmp = list1;
		list1 = list2;
		list2 = tmp;
	}
	if(list1->next == NULL)
		list1->next = list2;
	else
		list1->next = merge(list1->next, list2);
	return list1;
}
