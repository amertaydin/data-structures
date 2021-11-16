//
// Created by Mert Aydın on 16.11.2021.
//

#include <stdio.h>

int fun(int n) {
    static int x = 0;
    if (n > 0) {
        x++;
        return fun(n - 1) + x;
    }

    return 0;
}

int main() {
    int r;

    r = fun(5);

    printf("%d\n", r);

    return 0;
}

