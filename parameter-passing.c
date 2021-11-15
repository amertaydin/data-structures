//
// Created by Mert Aydın on 15.11.2021.
//

#include <stdio.h>

int addByValue(int a, int b) {
    int c;
    c = a + b;

    return c;
}

void swapByAddress(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1 = 10;
    int num2 = 15;
    int sum;

    sum = addByValue(num1, num2);
    printf("Sum is: %d\n", sum);

    printf("Num1: %d, Num2: %d\n", num1, num2);
    swapByAddress(&num1, &num2);
    printf("Num1: %d, Num2: %d\n", num1, num2);
}



