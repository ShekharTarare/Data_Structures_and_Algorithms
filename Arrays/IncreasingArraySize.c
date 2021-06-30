#include<stdio.h>
#include<stdlib.h>
int main(int argc, char **argv)
{
    //Suppose we have two arrays P and Q. If we want to increase the size of array P
    //then we can use Q to do that
    int *P, *Q, i;
    P = (int *)malloc(5*sizeof(int)); //Size = 5
    Q = (int *)malloc(10*sizeof(int)); //Size = 10

    P[0] = 1; P[1] = 2; P[2] = 3; P[3] = 4; P[4] = 5; //Initialize the P

    for(i = 0; i < 5; i++)
    {
        Q[i] = P[i]; //transfering the values from P to Q
    }

    free(P); //releasing the array P
    P = Q; //Passing the address of first value of array to the P
    Q = NULL; //Now, Q will not point to the array

    for(i = 0; i < 10; i++)
    {
        printf("%d\n", P[i]);
    }
    free(P); //release memory
    return 0;
}