#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 5;
    int b[5] = {2,4,6,8,10}; // Array created in stack

    int *p;
    int *ptr;
    p = &a;
    ptr = b; // Array b is already showing the address of the first element

    int *pointer;
    pointer = (int *)malloc(5*sizeof(int)); // malloc returns (void *) so it needs a cast.

    pointer[0] = 10;
    pointer[1] = 14;
    pointer[2] = 16;
    pointer[3] = 18;
    pointer[4] = 20;

    printf("%d\n", a);
    printf("%d\n", &a);
    printf("Address by using pointer %d\n", p);
    printf("Value by using pointer %d\n", *p);

    for(int i = 0; i < 5; i++) {
        printf("%d\n", ptr[i]);
    }

    for(int i = 0; i < 5; i++) {
        printf("%d\n", pointer[i]);
    }

    free(pointer);

    return 0;
}
