#include <stdio.h>

// Define the differential equation dy/dx = f(x, y)
 // Example equation: y' = x^2+y^2, y(0)=0. find y(0.4).
float f(float x, float y) {
    return x*x+y*y;
}

int main() {
    float x0, y0, h, x, y, m1, m2, m3, m4;
    int steps;

    // User input
    printf("Enter initial value of x (x0): ");
    scanf("%f", &x0);
    printf("Enter initial value of (y0): ");
    scanf("%f", &y0);
    printf("Enter step size (h): ");
    scanf("%f", &h);
    printf("Enter number of steps: ");
    scanf("%d", &steps);

    x = x0;
    y = y0;

   // printf("\nStep\tx\t\ty\n");
   // printf("0\t%.4f\t%.4f\n", x, y);

    // RK4 iterations
    for(int i = 1; i <= steps; i++) {
        m1= f(x, y);
        m2 = f(x + h/2, y + m1*h/2);
        m3 = f(x + h/2, y + m2*h/2);
        m4 = f(x + h, y + m3*h);

        y =y+ (m1 + 2*m2 + 2*m3 + m4)*h/6;
        x =x+ h;

        printf("%d\t%.4f\t%.4f\n", i, x, y);
    }

    return 0;
}
