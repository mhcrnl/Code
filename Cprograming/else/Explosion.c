#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

int x, y, w, h;

int count(long long int N)
{
	int result = 0, power = 1;
	int i = 0;
	for(i = N ; i >= 2 ; i /= 2)
	{
		result += (i + 1) * (i + 1) * i * power;
		power *= 4;
	}
	return result;
}

int calc_area(int X, int Y, long long int N)
{
	int a_w = ( (X + N / 2) < (x + w) ? (X + N / 2) : (x + w) ) - ( (X - N / 2) > x ? (X - N / 2) : x );
	int a_h = ( (Y + N / 2) < (y + h) ? (Y + N / 2) : (y + h) ) - ( (Y - N / 2) > y ? (Y - N / 2) : y );
	if(a_w < 0 || a_h < 0)	return 0;
	else	return (a_w + 1) * (a_h + 1);
}

int in_or_out(int X, int Y, long long int N)
{
	if( calc_area(X, Y, 3 * N) == (3 * N + 1) * (3 * N + 1) )	return 1;
	if( calc_area(X, Y, 3 * N) == 0 )	return -1;
	return 0;
}

int XPS(int X, int Y, long long int N)
{
	int flag = in_or_out(X, Y, N);
	if(flag == 1)	return count(N);
	if(flag == -1)	return 0;
	int total = calc_area(X, Y, N) * N;
	if(N == 2)	return total;
	int dx[4] = { (-3) * N / 4, 0, 3 * N / 4, 0 };
	int dy[4] = { 0, (-3) * N / 4, 0, 3 * N / 4 };
	int i = 0;
	for(i = 0 ; i < 4 ; i++)	total += XPS(X + dx[i], Y + dy[i], N / 2);
	return total;
}

int main(void)
{
	int X = 0, Y = 0;
	long long int N = 0;
	scanf("%d %d %lld %d %d %d %d", &X, &Y, &N, &x, &y, &w, &h);
	printf("%d\n", XPS(X, Y, N));
	return 0;
}
