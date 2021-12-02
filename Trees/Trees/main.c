//
//  main.c
//  Trees
//
//  Created by Mert Aydın on 3.12.2021.
//

#include <stdio.h>
#include "queue.h"

struct Node *root = NULL;

void Treecreate(void) {
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    
    printf("Enter root value: ");
    scanf("%d",&x);
    
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    
    while(!isEmpty(q)) {
        p = dequeue(&q);
        printf("Enter left child of %d ", p->data);
        scanf("%d",&x);
        
        if(x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        
        printf("Enter right child of %d ", p->data);
        scanf("%d",&x);
        
        if(x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
    
}

void Preorder(struct Node *p) {
    if(p) {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(struct Node *p) {
    if(p) {
        Preorder(p->lchild);
        printf("%d ", p->data);
        Preorder(p->rchild);
    }
}

void Postorder(struct Node *p) {
    if(p) {
        Preorder(p->lchild);
        Preorder(p->rchild);
        printf("%d ", p->data);
    }
}

int main(int argc, const char * argv[]) {
    Treecreate();
    printf("\nPre Order ");
    Preorder(root);
    printf("\nPost Order ");
    Postorder(root);
    printf("\nIn Order ");
    Inorder(root);
    return 0;
}
