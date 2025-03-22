#include <stdio.h>
//Trapeziodal Method

float func(float x) {
    return (1/(1+x*x));  // Function to integrate: f(x) = 1/(1+x^2)
}

int main() {
    float  x, a, b, h, sum;
    int i,n;

    // Input
    printf("Enter lower limit (a): ");
    scanf("%f", &a);
    printf("Enter upper limit (b): ");
    scanf("%f", &b);
    printf("Enter number of intervals (n): ");
    scanf("%d", &n);

    // Calculations
    h = (b - a) / n;
    sum = func(a) + func(b);  // Initialize with endpoints

    for(i = 1; i < n; i++) {
        x = a + i * h;
        sum = sum + 2 * func(x);  // Add middle terms
    }

    sum = sum * h / 2;  // Final multiplication

    // Output
    printf("\nIntegral value = %f", sum);
    return 0;
}
