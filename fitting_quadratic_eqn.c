#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

#define S 50

int main()
{
    int n, i;
    float x[S], y[S], sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0, a, b, A, B;

    system("cls"); // Clears the console screen

    /* Input */
    printf("How many data points? ");
    scanf("%d", &n);

    if (n > S)
    {
        printf("Number of data points exceeds the array size.\n");
        return -1;
    }

    for (i = 0; i < n; i++) // Changed loop to start from 0 for proper array indexing
    {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);

        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    /* Calculating Required Sums */
    for (i = 0; i < n; i++)
    {
        sumX = sumX + x[i];
        sumX2 = sumX2 + x[i] * x[i];
        sumY = sumY + log(y[i]); // Fixed variable name (sumY instead of sumy)
        sumXY = sumXY + x[i] * log(y[i]);
    }

    /* Calculating A and B */
    B = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    A = (sumY - B * sumX) / n;

    /* Transformation of A and B to a and b */
    a = exp(A);
    b = exp(B);

    /* Displaying values of a and b */
    printf("\nValues are: a = %.2f and b = %.2f\n", a, b);

    getch(); // Waits for a key press
    return 0;
}