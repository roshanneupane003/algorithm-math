#include <stdio.h>
#include <math.h>

#define F(x) (x * x * x - 9 * x + 1)

int main()
{
    int i = 1; // Initialize iteration counter
    float x1, x2, x0, y1, y2, y0;

    printf("Enter the value of x1: ");
    scanf("%f", &x1);

    printf("Enter the value of x2: ");
    scanf("%f", &x2);

    // Check if the initial guesses bracket the root
    y1 = F(x1);
    y2 = F(x2);

    if (y1 * y2 > 0)
    {
        printf("The given guesses do not bracket the root.\n");
        return -1; // Exit the program
    }

    printf("\nStep\tx1\t\tx2\t\tx0\t\tF(x0)\n");
    do
    {
        x0 = (x1 + x2) / 2; // Midpoint
        y0 = F(x0);         // Function value at x0

        printf("%d\t%f\t%f\t%f\t%f\n", i, x1, x2, x0, y0);

        // Update x1 or x2 based on the sign of F(x0)
        if (y1 * y0 < 0)
        {
            x2 = x0;
            y2 = y0;
        }
        else
        {
            x1 = x0;
            y1 = y0;
        }

        i++; // Increment iteration counter

    } while (fabs(y0) > 0.001); // Check if the function value is close enough to zero

    printf("\n\nApproximate root = %.4f\n\n", x0);

    return 0;
}