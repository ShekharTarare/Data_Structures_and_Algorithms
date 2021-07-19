#include<stdio.h>
#include<stdlib.h>
#define INT_MIN -32767
struct Node
{
    int data;
    struct Node *Next;
}*first = NULL;
void Create(int A[], int n)
{
    struct Node *t, *last;
    int i;
    first = (struct Node*)malloc(n*sizeof(struct Node));
    first -> Next = NULL;
    first -> data = A[0];
    last = first;

    for(i = 1; i < n ; i++)
    {
        t = (struct Node*)malloc(n*sizeof(struct Node));
        t -> Next = NULL;
        t -> data = A[i];
        last -> Next = t;
        last = t;
    }
}
int Max(struct Node *p)
{
    int max = p -> data;
    while(p != NULL)
    {
        if(max < p -> data)
            max = p -> data;
        p = p -> Next; 
    }
    return max;
}
int MaxUsingRecursion(struct Node *p)
{
    int x = 0;
    if(p == NULL)
        return INT_MIN;
    x = MaxUsingRecursion(p -> Next);
    if(x > p -> data)
        return x;
    else{
        return p -> data;
    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    Create(A, 5);
    printf("Maximum = %d", Max(first));
    printf("\nRecursion = %d", MaxUsingRecursion(first));
    return 0;
}