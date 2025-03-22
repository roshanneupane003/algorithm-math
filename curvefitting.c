#include <stdio.h>

int main()
{
  int n, i;
  float sx = 0, sy = 0, sxy = 0, sx2 = 0, a, b;

  printf("n: ");
  scanf("%d", &n);

  float x[n], y[n];

  printf("x:\n");
  for (i = 0; i < n; i++)
    scanf("%f", &x[i]);

  printf("y:\n");
  for (i = 0; i < n; i++)
    scanf("%f", &y[i]);

  for (i = 0; i < n; i++)
  {
    sx += x[i];
    sy += y[i];
    sxy += x[i] * y[i];
    sx2 += x[i] * x[i];
  }

  b = (n * sxy - sx * sy) / (n * sx2 - sx * sx);
  a = (sy / n) - (b * sx / n);

  printf("y = %f + %fx\n", a, b);
  return 0;
}