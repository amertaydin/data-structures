//
//  main.c
//  2D Arrays
//
//  Created by Mert Aydın on 17.11.2021.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {

    int A[3][4] = { {1,2,3,4}, {2,4,6,8}, {1,3,5,7,9} };
    
    int *B[3];
    
    int **C;
    
    int i,j;
    
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 4; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("Array A\n\n");

    
    printf("Array B\n\n");

    B[0] = (int *)malloc(4 * sizeof(int));
    B[1] = (int *)malloc(4 * sizeof(int));
    B[2] = (int *)malloc(4 * sizeof(int));
    
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 4; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    
    printf("Array C\n\n");
    
    C = (int **)malloc(3 * sizeof(int *));
    C[0] = (int *)malloc(4 * sizeof(int));
    C[1] = (int *)malloc(4 * sizeof(int));
    C[2] = (int *)malloc(4 * sizeof(int));
    
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 4; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
