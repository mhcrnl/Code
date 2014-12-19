#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int make_lotion(int D, int a, int b, int c, int A, int B, int C)
{
    if(D < 0) return 0;
    if(D == 0) return 1;
    if(a + b == 0)
    {
        if(D <= C * c)
            if(D % C == 0) return 1;
        return 0;
    }
    if(a + c == 0)
    {
        if(D <= B * b)
            if(D % B == 0) return 1;
        return 0;
    }
    if(b + c == 0)
    {
        if(D <= A * a)
            if(D % A == 0) return 1;
        return 0;
    }
    int flag = 0;
    if(a != 0) flag = make_lotion(D - A, a - 1, b, c, A, B, C);
    if(flag == 1) return 1;
    if(b != 0) flag = make_lotion(D - B, a, b - 1, c, A, B, C);
    if(flag == 1) return 1;
    if(c != 0) flag = make_lotion(D - C, a, b, c - 1, A, B, C);
    if(flag == 1) return 1;
    return 0;
}

int main()
{
    int D = 0, a = 0, b = 0, c = 0, A = 0, B = 0, C = 0, n = 0;
    int i = 0;
    scanf("%d", &n);
    for(i = 0 ; i < n ; i++)
    {
        scanf("%d %d %d %d %d %d %d", &D, &a, &b, &c, &A, &B, &C);
        if(A == B)
        {
            a += b;
            b = 0;
        }
        if(A == C)
        {
            a += c;
            c = 0;
        }
        if(B == C)
        {
            b += c;
            c = 0;
        }
        if(make_lotion(D, a, b, c, A, B, C) == 1) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
