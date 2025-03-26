#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
    float a[SIZE][SIZE], x[SIZE], x_new[SIZE];
    float temp, lambda_new = 0, lambda_old = 0, error;
    int i, j, n, step = 1;

    /* Inputs */
    printf("Enter Order of Matrix: ");
    scanf("%d", &n);
    printf("Enter Tolerable Error: ");
    scanf("%f", &error);

    /* Reading Matrix */
    printf("Enter Coefficients of Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }

    /* Reading Initial Guess Vector */
    printf("Enter Initial Guess Vector:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = ", i + 1);
        scanf("%f", &x[i]);
    }

    lambda_old = 1;

    /* Power Method */
    do
    {
        /* Multiplication */
        for (i = 0; i < n; i++)
        {
            temp = 0.0;
            for (j = 0; j < n; j++)
            {
                temp += a[i][j] * x[j];
            }
            x_new[i] = temp;
        }

        /* Finding Largest */
        lambda_new = fabs(x_new[0]);
        for (i = 1; i < n; i++)
        {
            if (fabs(x_new[i]) > lambda_new)
            {
                lambda_new = fabs(x_new[i]);
            }
        }

        /* Normalization */
        for (i = 0; i < n; i++)
        {
            x_new[i] = x_new[i] / lambda_new;
        }

        /* Display */
        printf("\n\nSTEP-%d:\n", step);
        printf("Eigen Value = %f\n", lambda_new);
        printf("Eigen Vector: \n");
        for (i = 0; i < n; i++)
        {
            printf("%f\t", x_new[i]);
        }
        printf("\n");

        /* Checking Accuracy */
        if (fabs(lambda_new - lambda_old) < error)
        {
            break;
        }

        lambda_old = lambda_new;
        for (i = 0; i < n; i++)
        {
            x[i] = x_new[i];
        }
        step++;
    } while (1);

    return 0;
}