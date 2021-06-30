#include<stdio.h>
#include<stdlib.h>
int main(int argc, char **argv)
{
    ////Static Arrays
    int A[5]; //declared and initialized with garbage values. Size = 5
    int B[] = {1, 2, 3, 4, 5}; //declared and initialized. Size = 5
    int C[5] = {5, 6, 7, 8, 9}; //declared and initialized. Size = 5 
    int D[5] = {6}; //6 at the 0th location and other location will be 
                    //filled with 0 as we are initializing, it will initialize all other with 0
    for(int i = 0; i < 5; i++)
    {
        printf("%d\n", A[i]); //A has been initialized with garbage values
    }
    for(int i = 0; i < 5; i++)
    {
        printf("%d\n", D[i]); //D has been initialized with 6 at first and others with zeroes
    }

    ////Dynamic Arrays
    int *P; //declared a poiner variable of type int
    P = (int *)malloc(5*sizeof(int)); //saved the address of the array which is in heap to the pointer P
    P[0] = 1;
    for(int i = 0; i < 5; i++)
    {
        printf("%d\n", P[i]);
    }
    free(P); //releasing memory
    return 0;
}