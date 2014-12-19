#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main()
{
    FILE *fp;
    int count[70000] = {0};
    int i = 0;
    int total = 0, max = 0;
    char filename[300];
    scanf("%s", filename);
    fp = fopen(filename, "rb");
    assert( fp != NULL );
    fread(&total, 4, 1, fp);
    short int input[total];
    fread(input, sizeof(short int), total, fp);
    for(i = 0 ; i < total ; i++) count[(int)input[i] + 32768]++;
    for(i = 1 ; i < 70000 ; i++)
        if(count[max] <= count[i]) max = i;
    printf("%d\n%d\n", max - 32768, count[max]);
    fclose(fp);
    return 0;
}
