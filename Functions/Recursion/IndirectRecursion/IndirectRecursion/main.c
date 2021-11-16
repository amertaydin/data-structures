//
//  main.c
//  IndirectRecursion
//
//  Created by Mert Aydın on 16.11.2021.
//

#include <stdio.h>

void B(int n);

void A(int n) {
    if (n > 0) {
        printf("%d ", n);
        B(n - 1);
    }
}

void B(int n) {
    if (n > 1) {
        printf("%d ", n);
        A(n / 2);
    }
}

int main() {
    
    A(20);
    return 0;
}
