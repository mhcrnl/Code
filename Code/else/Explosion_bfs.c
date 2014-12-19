#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define MAX 50000000

typedef struct bomb
{
	int X;
	int Y;
	int N;
	int x;
	int y;
	int w;
	int h;
}
BOMB;

typedef struct que
{
	BOMB b[MAX];
	int start;
	int end;
}
QUE;

QUE q;

void init_que(QUE *q)
{
	q->start = 0;
	q->end = 0;
	return;
}

void push_que(QUE *q, int X, int Y, int N, int x, int y, int w, int h)
{
	q->b[ q->end ].X = X;
	q->b[ q->end ].Y = Y;
	q->b[ q->end ].N = N;
	q->b[ q->end ].x = x;
	q->b[ q->end ].y = y;
	q->b[ q->end ].w = w;
	q->b[ q->end ].h = h;
	q->end = (q->end + 1) % MAX;
	if(q->end == q->start) printf("error-full\n");
	return;
}

int calc_area(BOMB *b)
{
	int a_w = ( (b->X + b->N / 2) < (b->x + b->w) ? (b->X + b->N / 2) : (b->x + b->w) ) - ( (b->X - b->N / 2) > b->x ? (b->X - b->N / 2) : b->x );
	int a_h = ( (b->Y + b->N / 2) < (b->y + b->h) ? (b->Y + b->N / 2) : (b->y + b->h) ) - ( (b->Y - b->N / 2) > b->y ? (b->Y - b->N / 2) : b->y );
	if(a_w < 0 || a_h < 0) return 0;
	else return (a_w + 1) * (a_h + 1);
}

int pop_que(QUE *q)
{
	int out = q->b[ q->start ].N * calc_area( &(q->b[ q->start ]) );
	q->start = (q->start + 1) % MAX;
	return out;
}

int getsize_que(QUE *q)
{
	return (q->end + MAX - q->start) % MAX; 
}


int XPS(int X, int Y, int N, int x, int y, int w, int h)
{
	int total = 0;
	init_que(&q);
	push_que(&q, X, Y, N, x, y, w, h);
	while( getsize_que(&q) != 0 )
	{
		N = q.b[ q.start ].N;
		X = q.b[ q.start ].X;
		Y = q.b[ q.start ].Y;
		if(N > 2)
		{
			int dx[4] = { (-3) * N / 4, 0, 3 * N / 4, 0 };
			int dy[4] = { 0, (-3) * N / 4, 0, 3 * N / 4 };
			int i = 0;
			for(i = 0 ; i < 4 ; i++) 	push_que(&q, X + dx[i], Y + dy[i], N / 2, x, y, w, h);
		}
		total += pop_que(&q);
	}
	return total;
}

int main(void)
{
	int X = 0, Y = 0, N = 0, x = 0, y = 0, w = 0, h = 0;
	scanf("%d %d %d %d %d %d %d", &X, &Y, &N, &x, &y, &w, &h);
	printf("%d\n", XPS(X, Y, N, x, y, w, h));
	return 0;
}
