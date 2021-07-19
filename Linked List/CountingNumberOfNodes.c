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
    first = (struct Node*)malloc(n*sizeof(struct Node));
    first -> data = A[0];
    first -> Next = NULL;
    last = first;

    for(i = 1; i < n; i++)
    {
        t = (struct Node*)malloc(n*sizeof(struct Node));
        t -> data = A[i];
        t -> Next = NULL;
        last -> Next = t;
        last = t;
    }
}
int CountNumberOfNodes(struct Node *p)
{
    int count = 0;
    while(p != NULL)
    {
        count++;
        p = p -> Next;
    }
    return count;
}
int CountNumberOfNodesRecursive(struct Node *p)
{
    if(p == NULL)
        return 0;
    else
        return CountNumberOfNodesRecursive(p -> Next) + 1;
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    Create(A, 5);
    printf("Number of Nodes = %d", CountNumberOfNodes(first));
    printf("\nRecursive = %d", CountNumberOfNodesRecursive(first));
    return 0;
}