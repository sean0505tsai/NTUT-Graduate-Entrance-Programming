#include <stdio.h>
float f1(int a, int b) {
    return (float) b / a + b % a;
}

int f2() {
    enum MONTH {Jan, Feb=2, Mar, Apr, May, Jun=9, Jul};
    return (Jun / Apr + May % 3 + Jan * Jul);
}

int f3(int x, int y) {
    int t = x < y ? x : y;
    return (t << y);
}

int f4() {
    int sum = 0, myArray[5] = {1, 2, 3, 4, 5};
    int *ptr = myArray;
    for (int i = 0; i < 5; ++i, ++ptr) {
        sum += *ptr;
    }
    return sum;
}

int f5() {
    int sum = 0;
    int A[3][3] = {{1, 1, 1}, {2, 1, 2}, {2, 1, 2}};
    int B[3][3] = {{1, 1, 1}, {2, 2, 2}, {1, 1, 1}};
    int C[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    for (int index = 0; index < 9; ++index) {
        int i = index / 3;
        int j = index % 3;
        for (int k = 0; k < 3; ++k) {
            C[i][j] += A[i][k] * B[k][j];
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) {
                sum += C[i][j];
            }
        }
    }
    return sum;
}

int main() {
    // Problem 2-1
    printf("%3.2f\n", f1(2, 3)); 

    // Problem 2-2
    printf("%d\n", f2()); 

    // Problem 2-3
    printf("%d\n", f3(3, 4)); 

    // Problem 2-4
    printf("%d\n", f4()); 

    // Problem 2-5
    printf("%d\n", f5()); 

    return 0;
}