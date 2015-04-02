#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
	int x[250000];
	int y[250000];
	int start;
	int end;
}
QUEUE;

int table[500][500];
QUEUE que;
int area[250000];
int d[500][500];
int dir_x[4] = {-1, 0, 0, 1};
int dir_y[4] = {0, -1, 1, 0};

int bfs_lake(int N, int M, int i, int j)
{
	int result = 1;
	que.start = 0;
	que.end = 1;
	que.x[que.start] = i;
	que.y[que.start] = j;
	table[i][j] = 0;
	while( (que.end + 250000 -  que.start) % 250000 != 0)
	{
		int now_x = que.x[que.start];
		int now_y = que.y[que.start];
		que.start = (que.start + 1) % 250000;
		int i = 0;
		for(i = 0 ; i < 4 ; i++)
		{
			int tmp_x = now_x + dir_x[i];
			int tmp_y = now_y + dir_y[i];
			if(tmp_x >= 0 && tmp_x < N && tmp_y >=0 && tmp_y < M && table[tmp_x][tmp_y] == 1)
			{
				que.x[que.end] = tmp_x;
				que.y[que.end] = tmp_y;
				table[tmp_x][tmp_y] = 0;
				que.end = (que.end + 1) % 250000;
				result++;	
			}
		}
	}
	return result;
}

int main()
{
	int N = 0, M = 0, count = 0;
	int i = 0, j = 0;
	scanf("%d %d", &N, &M);
	for(i = 0 ; i < N ; i++)
		for(j = 0 ; j < M ; j++) scanf("%d", &table[i][j]);
	for(i = 0 ; i < N ; i++)
		for(j = 0 ; j < M ; j++)
			if(table[i][j] == 1) area[count++] = bfs_lake(N, M, i, j);
	for(i = 0 ; i < count - 1; i++)
		for(j = i + 1 ; j < count ; j++)
			if(area[i] < area[j])
			{
				int tmp = area[i];
				area[i] = area[j];
				area[j] = tmp;
			}
	for(i = 0 ; i < count ; i++) printf("%d\n", area[i]);
	return 0;
}