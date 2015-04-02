#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "heap.h"

void initialize(struct Heap *heap)
{
	heap->n = 0;
	return;
}

int removeMin(struct Heap *heap)
{
	int out = heap->data[1];
	heap->data[1] = heap->data[(heap->n)--];
	int now = 1;
	while(now * 2 <= heap->n)
	{
		int next = now * 2;
		if(next + 1 <= heap->n && heap->data[next + 1] < heap->data[next])	next++;
		if(heap->data[next] < heap->data[now])
		{
			int tmp = heap->data[next];
			heap->data[next] = heap->data[now];
			heap->data[now] = tmp;
			now = next;
		}
		else	break;
	}
	return out;
}

void add(struct Heap *heap, int i)
{
	int now = ++(heap->n);
	heap->data[now] = i;
	while(now > 1 && heap->data[now] < heap->data[now / 2])
	{
		int tmp = heap->data[now];
		heap->data[now] = heap->data[now / 2];
		heap->data[now / 2] = tmp;
		now /= 2;
	}
	return;
}

int isFull(struct Heap *heap)
{
	return (heap->n == MAXHEAP);
}

int isEmpty(struct Heap *heap)
{
	return (heap->n == 0);
}
