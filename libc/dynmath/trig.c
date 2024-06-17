#include <stdio.h>

// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n == 0) return 1;
    unsigned long long fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

// Function to calculate power
double power(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

// Function to calculate cosine using Taylor series
double cos(double x) {
    double cosx = 0.0;
    int terms = 10;  // Number of terms in the Taylor series

    for (int n = 0; n < terms; ++n) {
        double term = power(-1, n) * power(x, 2 * n) / factorial(2 * n);
        cosx += term;
    }

    return cosx;
}

// Function to calculate sine using Taylor series
double sin(double x) {
    double sinx = 0.0;
    int terms = 10;  // Number of terms in the Taylor series

    for (int n = 0; n < terms; ++n) {
        double term = power(-1, n) * power(x, 2 * n + 1) / factorial(2 * n + 1);
        sinx += term;
    }

    return sinx;
}

// Function to calculate tangent
double tangent(double x) {
    return sine(x) / cosine(x);
}


