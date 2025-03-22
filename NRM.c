#include <stdio.h>
#include <math.h>

#define E 0.0001

float a, b, c;

float f(float x) { return a * x * x + b * x + c; }
float d(float x) { return 2 * a * x + b; }

int main()
{
    float x0, x, df;
    int m, i;

    printf("a b c: ");
    scanf("%f %f %f", &a, &b, &c);
    printf("m: ");
    scanf("%d", &m);
    printf("x0: ");
    scanf("%f", &x0);

    for (i = 1; i <= m; i++)
    {
        df = d(x0);
        if (fabs(df) < E)
        {
            printf("df small\n");
            return 0;
        }
        x = x0 - f(x0) / df;
        printf("i=%d r=%f\n", i, x);
        if (fabs(x - x0) < E)
        {
            printf("c %d r=%f\n", i, x);
            return 0;
        }
        x0 = x;
    }
    printf("m r=%f\n", x);
    return 0;
}