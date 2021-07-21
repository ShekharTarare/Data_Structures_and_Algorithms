#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *Next;
}*first = NULL;
void Create(int A[], int size)
{
    struct Node *t, *last;
    int i;
    first = (struct Node *)malloc(sizeof(struct Node));
    first -> Next = NULL;
    first -> data = A[0];
    last = first;

    for(i = 1; i < size; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> Next = NULL;
        t -> data = A[i];
        last -> Next = t;
        last = t;
    }
}
void InsertAtLast(struct Node *p, int x)
{
    struct Node *t, *last;
    t = (struct Node *)malloc(sizeof(struct Node));
    t -> data = x;
    t -> Next = NULL;

    if(p == NULL)
    {
        p = last = t;
    }
    else
    {
        last = p;
        while(last -> Next != NULL)
            last = last -> Next;
        last -> Next= t;
        last = t;
    }
}
void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p -> data);
        p = p -> Next;
    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    Create(A, 5);

    InsertAtLast(first, 6);
    printf("\nElements are : ");
    Display(first);
    return 0;
}