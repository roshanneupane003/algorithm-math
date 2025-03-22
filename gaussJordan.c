#include <stdio.h>

int main()
{
   int n, i, j, k;
   float ratio, a[10][11];

   printf("n: ");
   scanf("%d", &n);

   printf("A:\n");
   for (i = 1; i <= n; i++)
      for (j = 1; j <= n + 1; j++)
         scanf("%f", &a[i][j]);

   for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++)
         if (j != i)
         {
            ratio = a[j][i] / a[i][i];
            for (k = 1; k <= n + 1; k++)
               a[j][k] -= ratio * a[i][k];
         }

   printf("R:\n");
   for (i = 1; i <= n; i++)
      printf("x%d = %f\n", i, a[i][n + 1] / a[i][i]);

   return 0;
}