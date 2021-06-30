#include<stdio.h>
#include<stdlib.h>
int main()
{
    ////First method. Everything will be in stack
    int i, j;
    int A[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    printf("Method 1\n");

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    ////Second method
    int *B[3]; //created in stack. Array of integer pointer
    B[0] = (int *)malloc(4*sizeof(int)); //will be created in heap
    B[1] = (int *)malloc(4*sizeof(int)); //will be created in heap
    B[2] = (int *)malloc(4*sizeof(int)); //will be created in heap

    printf("\nMethod 2\n");

    //Let's initialize with some values 
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            B[i][j] = j;
        }
    }

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    
    ////Third method. Using double pointer. Everything will be in heap
    int **C; //Created in stack

    printf("\nMethod 3\n");

    C = (int **)malloc(3*sizeof(int)); //will be created in heap
    C[0] = (int *)malloc(4*sizeof(int)); 
    C[1] = (int *)malloc(4*sizeof(int)); 
    C[2] = (int *)malloc(4*sizeof(int)); 

//Let's initialize with some values 
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            C[i][j] = j;
        }
    }

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}