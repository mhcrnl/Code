#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
    FILE *fp_in, *fp_out;
    int key = 0, c = 0;
    scanf("%d", &key);
    fp_in = fopen("test", "rb");
    assert(fp_in != NULL);
    fp_out = fopen("test.enc", "wb");
    assert(fp_out != NULL);
    while( (c = fgetc(fp_in)) != EOF )
    {
        c = c ^ key;
        fputc(c, fp_out);
    }
    return 0;
}
