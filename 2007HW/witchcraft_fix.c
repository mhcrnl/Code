#include <stdio.h>

int mp(int D, int a0, int b0, int c0,int a, int b, int c, int A, int B, int C) {
	int flag = 0;
	if(D == 0)	return 1;
	else if (D > 0)
	{
		if(a > 0 && b == b0 && c == c0) flag += mp(D - A, a0, b0, c0, a - 1, b, c, A, B, C);
		if(flag == 0 && b > 0 && c == c0)	flag += mp(D - B, a0, b0, c0, a, b - 1, c, A, B, C);
		if(flag == 0 && C > 0 && D % C == 0 && D / C <= c) 	flag += 1;
	}
	return flag;
}

int main ()
{
	int N, D, a, b, c, A, B, C;
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &D);
		scanf("%d%d%d", &a, &b, &c);
		scanf("%d%d%d", &A, &B, &C);
		if(mp(D, a, b, c, a, b, c, A, B, C) != 0) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}