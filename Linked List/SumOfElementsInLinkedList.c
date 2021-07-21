#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *Next;
}*first = NULL;
void Create(int A[], int n)
{
    struct Node *t, *last;
    int i;
    first = (struct Node*)malloc(sizeof(struct Node));
    first -> data = A[0];
    first -> Next = NULL;
    last = first;

    for(i = 1; i < n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t -> Next = NULL;
        t -> data = A[i];
        last -> Next = t;
        last = t;
    }
}
int SumOfElements(struct Node *p)
{
    int sum = 0;
    while(p != NULL)
    {
        sum = sum + p ->data;
        p = p -> Next;
    }
    return sum;
}
int SumOfElementsRecursive(struct Node *p)
{
    if(p == NULL)
        return 0;
    else
        return SumOfElementsRecursive(p -> Next) + p -> data;
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    Create(A, 5);
    printf("Sum of Elements = %d", SumOfElements(first));
    printf("\nRecursive = %d", SumOfElementsRecursive(first));
    return 0;
}