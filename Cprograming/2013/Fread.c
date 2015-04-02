#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char name[100];
  int i = 0;
  scanf("%s",name);
  FILE *fp;
  fp = fopen(name, "rb");
  int n[1] = {0};
  int result[70000] = {0}, max = 0;
  fread(n, sizeof(n[0]), 1, fp);
  short int input[ n[0] ];
  fread(input, sizeof(short int), n[0], fp);
  fclose(fp);
  for(i=0 ; i < n[0] ; i++) result[ input[i]+32768 ]++;
  for(i=0 ; i < 70000 ; i++)  if(result[i] >= result[max]) max = i;
  printf("%d\n%d\n", max-32768, result[max]);
  return 0;
}
