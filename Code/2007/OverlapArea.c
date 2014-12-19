#include <stdio.h>
#include <stdlib.h>

#define A 0
#define B 1
#define C 2
#define AB 3
#define AC 4
#define BC 5
#define ABC 6

typedef struct rec
{
    long long int l;
    long long int b;
    long long int r;
    long long int t;
    long long int a;
}
REC;

void set_rec(REC r[6], int a, int b, int ab)
{
    r[ab].l = r[a].l > r[b].l ? r[a].l : r[b].l;
    r[ab].r = r[a].r < r[b].r ? r[a].r : r[b].r;
    r[ab].b = r[a].b > r[b].b ? r[a].b : r[b].b;
    r[ab].t = r[a].t < r[b].t ? r[a].t : r[b].t;
    if( (r[ab].r - r[ab].l <= 0) || (r[ab].t - r[ab].b) <= 0 ) r[ab].a = 0;
    else r[ab].a = (r[ab].r - r[ab].l) * (r[ab].t - r[ab].b);
    return;
}

int main()
{
    REC r[7];
    int i = 0;
    for(i = 0 ; i < 3 ; i++)
    {
        scanf("%lld %lld %lld %lld", &r[i].l, &r[i].b, &r[i].r, &r[i].t);
        r[i].a = (r[i].r - r[i].l) * (r[i].t - r[i].b);
    }
    set_rec(r, A, B, AB);
    set_rec(r, A, C, AC);
    set_rec(r, B, C, BC);
    if(r[AB].a != 0) set_rec(r, AB, C, ABC);
    else r[ABC].a = 0;
    printf("%lld\n", r[A].a + r[B].a + r[C].a - r[AB].a - r[AC].a - r[BC].a + r[ABC].a);
    return 0;
}
