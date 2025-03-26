#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

#define S 50

int main()
{
    int n, i;
    float x[S], y[S], sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0, a, b, A;

    system("cls"); // Clear the console screen

    /* Input */
    printf("How many data points?\n");
    scanf("%d", &n);

    if (n > S)
    {
        printf("Number of data points exceeds the array size.\n");
        return -1; // Exit if the number of data points is too large
    }

    for (i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);

        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    /* Calculating Required Sums */
    for (i = 0; i < n; i++)
    {
        sumX = sumX + log(x[i]);
        sumX2 = sumX2 + log(x[i]) * log(x[i]);
        sumY = sumY + log(y[i]);
        sumXY = sumXY + log(x[i]) * log(y[i]);
    }

    /* Calculating A and b */
    b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    A = (sumY - b * sumX) / n;

    /* Transformation of A to a */
    a = exp(A);

    /* Displaying value of a and b */
    printf("\nValues are: a = %.2f and b = %.2f\n", a, b);

    getch(); // Wait for a key press
    return 0;
}