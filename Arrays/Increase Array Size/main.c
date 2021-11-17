//
//  main.c
//  Increase Array Size
//
//  Created by Mert Aydın on 17.11.2021.
//

#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char * argv[]) {
    int *p, *q;
    
    p = (int *)malloc(5 * sizeof(int));
    
    p[0] = 2;
    p[1] = 12;
    p[2] = 22;
    p[3] = 32;
    p[4] = 42;
    
    q = (int *)malloc(10 * sizeof(int));
    
    for(int i = 0; i < 5; i++) {
        q[i] = p[i];
    }
    
    free(p);
    
    p = q; // Now they are pointing the same location
    
    q = NULL; // q is pointing to nowhere
    
    for(int i = 0; i < 5; i++) {
        printf("%d\n", p[i]);
    }
    
    return 0;
}
