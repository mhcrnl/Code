#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int remove_comment(const char *program, char *program_without_comment)
{
    int n = 2, p = 0;
    int mode = 0, count = 0, flag = 0;
    while(n <= strlen(program) + 2)
    {
        flag = 0;
        switch(mode)
        {
            case 3:
                if(program[(n - 1)] == 34 && program[(n - 2)] != 92) mode = 0;
                if(program[(n - 1)] == 34 && program[(n - 2)] == 92)
                {
                    int sign = 0;
                    while(program_without_comment[p - (1 + sign)] == 92) sign++;
                    if(sign % 2 == 1) mode = 0;
                }
                break;
            case 0:
                if(program[(n - 2)] == '/' && program[(n - 1)] == '/') mode = 1;
                if(program[(n - 2)] == '/' && program[(n - 1)] == '*') mode = 2;
                if(program[(n - 1)] == 34 && program[(n - 2)] != 92) mode = 3;
                if(program[(n - 1)] == 34 && program[(n - 2)] == 92)
                {
                    int sign = 0;
                    while(program_without_comment[p - (1 + sign)] == 92) sign++;
                    if(sign % 2 == 1) mode = 3;
                }
                break;
            case 1:
                if(program[(n - 2)] == 10)
                {
                    program_without_comment[p++] = program[(n - 2)];
                    mode = 0;
                    count++;
                    flag = 1;
                }
                break;
            case 2:
                if(program[(n - 2)] == '*' && program[(n - 1)] == '/')
                {
                    n++;
                    mode = 0;
                    count++;
                    flag = 1;
                }
                break;
        }
        if((flag == 0 && mode == 0) || mode == 3) program_without_comment[p++] = program[(n - 2)];
        n++;
    }
    return count;
}

int main()
{
    char input[10000], output[10000];
    int n = 0;
    while(scanf("%c", &input[n]) != EOF) n++;
    printf("%d\n", remove_comment(input,output));
    printf("%s\n", output);
    return 0;
}
