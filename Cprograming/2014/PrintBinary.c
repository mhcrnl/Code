#include <stdio.h>

int main()
{
    long long int input = 0;
    int i = 0;
    while(scanf("%lld", &input) != EOF)
    {
        for(i = 63 ; i >= 0 ; i--) printf("%lld", (input >> i) & 1);
        printf("\n");
    }
    return 0;
}
