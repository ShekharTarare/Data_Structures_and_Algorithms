#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    int data;
    struct Node *Prev;
    struct Node *Next;
}*first = NULL;
void Create(int A[], int size)
{
    struct Node *t, *last;
    int i;
    first = (struct Node *)malloc(sizeof(struct Node));
    first -> data = A[0];
    first -> Next = first -> Prev = NULL;
    last = first;

    for(i = 1; i < size; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> Prev = last;
        t -> Next = last -> Next;
        last -> Next = t;
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
void Reverse(struct Node *p)
{
    struct Node *t;
    while(p != NULL)
    {
        t = p -> Next;
        p -> Next = p -> Prev;
        p -> Prev = t;
        p = p -> Prev;
        if(p != NULL && p -> Next == NULL)
            first = p;
    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    Create(A, 5);
    printf("\nBefore Reverse: ");
    Display(first);
    Reverse(first);
    printf("\nAfter Reverse: ");
    Display(first);
    return 0;
}