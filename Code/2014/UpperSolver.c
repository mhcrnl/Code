#include <stdio.h>
#define N 256

void upper_solver(double *A, double *x, double *y, int n)
{
  int i = 0, j = 0;
  A += ((n * (n + 1)) / 2 - 1);
  double tmp = 0;
  for(i = n - 1; i >= 0; i--)
  {
    tmp = 0;
    for(j = n - 1; j > i; j--)
    {
      tmp += (*A) * x[j];
      A--;
    }
    x[i] = (y[i] - tmp) / (*A);
    A--;
  }
  return;
}

int main()
{
  int i, j;
  int n; 
  double A[N * (N + 1) / 2];
  double *aptr = A;
  double x[N];
  double y[N];
  scanf("%d", &n);
  for ( i = 0 ; i < n ; i++ )
    for ( j = i ; j < n ; j++ ) {
      scanf("%lf", aptr);
      aptr++;
    }
  for ( i = 0 ; i < n ; i++ )
    scanf("%lf", &(y[i]));
  upper_solver(A, x, y, n);
  for ( i = 0 ; i < n ; i++ )
    printf("%lf\n", x[i]);

  return 0;
}
