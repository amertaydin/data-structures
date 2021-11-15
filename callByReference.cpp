//
// Created by Mert Aydın on 15.11.2021.
//

#include <iostream>

using namespace std;

void swapByAddress(int &a, int &b) { // Call by Reference
    int temp;

    temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1 = 10;
    int num2 = 15;

    printf("Num1: %d, Num2: %d\n", num1, num2);
    swapByAddress(num1, num2); // Works only in C++
    printf("Num1: %d, Num2: %d\n", num1, num2);
}




