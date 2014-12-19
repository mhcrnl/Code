#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* to_plural(char input[100])
{
    int n = strlen(input);
    switch(input[n - 1])
    {
        case's': 
        case'z':
        case'x':
            input[n] = 'e';
            input[n + 1] = 's';
            input[n + 2] = '\0';
            break;
        case'h':
            if(input[n - 2] == 'c' || input[n - 2] == 's')
            {
                input[n] = 'e';
                input[n + 1] = 's';
                input[n + 2] = '\0';
            }
            else 
            {
                input[n] = 's';
                input[n + 1] = '\0';
            }
            break;
        case'y':
            if(input[n - 2] == 'a' || input[n - 2] == 'e' || input[n - 2] == 'i' || input[n - 2] == 'o' || input[n - 2] == 'u')
            {
                input[n] = 's';
                input[n + 1] = '\0';
            }
            else
            {
                input[n - 1] = 'i';
                input[n] = 'e';
                input[n + 1] = 's';
                input[n + 2] = '\0';
            }
            break;
        default:
            input[n] = 's';
            input[n + 1] = '\0';
    }
    return input;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    char input[n][100];
    int i = 0;
    for(i = 0 ; i < n ; i++) scanf("%s", input[i]);
    for(i = 0 ; i < n ; i++) printf("%s\n", to_plural(input[i]));
    return 0;
}
