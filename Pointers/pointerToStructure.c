//
// Created by Mert Aydın on 15.11.2021.
//

#include <stdio.h>
#include <stdlib.h>

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    // Created in Stack
    struct Rectangle r = {10,5};
    printf("%d %d\n", r.length, r.breadth);

    struct Rectangle *p=&r;
    printf("%d %d\n", p->length, p->breadth);

    // Created in Heap
    struct Rectangle *s;
    s = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    s->length = 15;
    s->breadth = 7;

    printf("%d %d\n", s->length, s->breadth);

    free(s);
}
