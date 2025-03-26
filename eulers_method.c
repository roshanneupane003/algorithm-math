#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define f(x, y) (x + y) // Definition of the function

int main()
{
    float x0, y0, xn, h, yn, slope;
    int i, n;

    system("cls"); // Clear the console screen

    /* Input */
    printf("Enter Initial Condition\n");
    printf("x0 = ");
    scanf("%f", &x0);

    printf("y0 = ");
    scanf("%f", &y0);

    printf("Enter calculation point xn = ");
    scanf("%f", &xn);

    printf("Enter number of steps: ");
    scanf("%d", &n);

    /* Calculating step size (h) */
    h = (xn - x0) / n;

    /* Euler's Method */
    printf("\n x0\t\ty0\t\tslope\t\tyn\n");
    printf("----------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        slope = f(x0, y0);   // Calculate the slope
        yn = y0 + h * slope; // Calculate the next y value

        printf("%.4f\t%.4f\t%.4f\t%.4f\n", x0, y0, slope, yn);

        y0 = yn;     // Update y0 for the next step
        x0 = x0 + h; // Update x0 for the next step
    }

    /* Displaying result */
    printf("\nValue of y at x = %.2f is %.3f\n", xn, yn);

    getch(); // Wait for user input before closing the program
    return 0;
}