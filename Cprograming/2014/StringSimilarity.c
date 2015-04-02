#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    char output[n][10];
    for(i = 0 ; i < n ; i++)
    {
        char input[2][100001];
        int count[2][256] = {{0}};
        scanf("%s%s", input[0], input[1]);
        int len_1 = strlen(input[0]), len_2 = strlen(input[1]);
        int j = 0, trans = 0;
        for(j = 0 ; j < len_1 ; j++)
        {
            trans = input[0][j];
            count[0][trans]++;
        }
        for(j = 0 ; j < len_2 ; j++)
        {
            trans = input[1][j];
            count[1][trans]++;
        }
        for(j = 97 ; j < 123 ; j++) if( (count[0][j] + count[0][j - 32]) != (count[1][j] + count[1][j - 32]) ) break;
        if(j == 123) strcpy(output[i], "yes");
        else strcpy(output[i], "no");
    }
    for(i = 0 ; i < n ; i++) printf("%s\n", output[i]);
    return 0;
}
