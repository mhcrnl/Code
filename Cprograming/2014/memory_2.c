#include <stdio.h>
#include <stdlib.h>
#include "memory_2.h"

void initMemory(Memory *memory, int length)
{
	memory->start = -1;
	memory->end = -2;

	Memory *new, *tail;
	new = (Memory*)malloc(sizeof(Memory));
	tail = (Memory*)malloc(sizeof(Memory));
	new->start = 0;
	new->end = length;
	tail->start = -1;
	tail->end = -2;

	memory->next = new;
	new->next = tail;
	tail->next = NULL;

	return;
}

void refresh(Memory *memory)
{
	Memory *tmp = memory, *discard;
	while(tmp->next->start != -1)
	{
		if(tmp->next->end == tmp->next->start)
		{
			discard = tmp->next;
			tmp->next = tmp->next->next;
			free(discard);
		}
		else if(tmp->next->start == tmp->end)
		{
			tmp->end = tmp->next->end;
			discard = tmp->next;
			tmp->next = tmp->next->next;
			free(discard);
		}
		else	tmp = tmp->next;
	}
	return;
}

void printMemory(Memory *memory)
{
	printf("==========\n");
	Memory *tmp;
	tmp = memory->next;
	while(tmp->start != -1)
	{ 
		printf("start %d, length %d\n", tmp->start ,tmp->end - tmp->start);
		tmp = tmp->next;
	}
	return;
}

void allocateMemory(Memory *memory, int start, int length)
{
	Memory *tmp;
	tmp = memory->next;
	while(tmp->end < start + length)	tmp = tmp->next;
	
	Memory *new;
	new = (Memory*)malloc(sizeof(Memory));
	new->start = start + length;
	new->end = tmp->end;
	new->next = tmp->next;
	tmp->next = new;
	tmp->end = start;
	
	refresh(memory);
	return;
}

void freeMemory(Memory *memory, int start, int length)
{
	Memory *tmp;
	tmp = memory;
	while(tmp->next->start < start + length && tmp->next->start != -1)	tmp = tmp->next;
	
	Memory *new;
	new = (Memory*)malloc(sizeof(Memory));
	new->start = start;
	new->end = start + length;
	new->next = tmp->next;
	tmp->next = new;
	
	refresh(memory);
	return;
}
