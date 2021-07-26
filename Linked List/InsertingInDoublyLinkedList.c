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
void Insert(struct Node *p, int data, int pos)
{
    struct Node *t;
    int i;
    if(pos == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = data;
        t -> Prev = t -> Next = NULL;
        if(first == NULL)
            first = t;
        else
        {
            t -> Next = first;
            first -> Prev = t;
            first = t;
        }
    }
    else if(pos > 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = data;
        t -> Prev = t -> Next = NULL;
        for(i = 0; i < pos - 1; i++)
            p = p -> Next;
        if(p -> Next == NULL)
        {
            printf("\nPosition cannot be greater than size of linked list!\n");
        }
        else
        {
            t -> Prev = p;
            t -> Next = p -> Next;
            p -> Next -> Prev = t;
            p -> Next = t;
        }
    }
    else
    {
        printf("\nInvalid position!\n");
    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5}, data, pos;
    Create(A, 5);
    printf("\nEnter the element to insert: ");
    scanf("%d", &data);
    printf("\nEnter the position: ");
    scanf("%d", &pos);
    printf("\nBefore Insert: ");
    Display(first);
    Insert(first, data, pos);
    printf("\nAfter Insert: ");
    Display(first);
    return 0;
}