#define MAXHEAP 100

struct Heap
{
	int data[MAXHEAP + 1];
	int n;
};

void initialize(struct Heap *heap);
int removeMin(struct Heap *heap);
void add(struct Heap *heap, int i);
int isFull(struct Heap *heap);
int isEmpty(struct Heap *heap);
