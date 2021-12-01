//
//  main.c
//  StackLinkedList
//
//  Created by Mert Aydın on 1.12.2021.
//

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
}*top = NULL;

void push(int x) {
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    
    if(t == NULL) {
        printf("Stack is full\n");
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop(void) {
    struct Node *t;
    int x = -1;

    if(top == NULL) {
        printf("Stack is Empty\n");
    } else {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    
    return x;
}

void Display(void) {
    struct Node *p;
    p = top;
    
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    
    push(10);
    push(20);
    push(30);
    
    Display();
    
    printf("%d ", pop());
     
    return 0;
}
