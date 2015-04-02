#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main()
{
	struct Heap heap;
	initialize(&heap);
	if(isEmpty(&heap))
	{
		add(&heap, 1);
		add(&heap, 1);
		add(&heap, 5);
		add(&heap, 3);
	}
	if(isFull(&heap))	add(&heap, 7);
	while(!isEmpty(&heap))	printf("%d\n", removeMin(&heap));
	return 0;
}
