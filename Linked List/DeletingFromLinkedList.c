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
        t -> data = A[i];
        t -> Next = NULL;
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
int DeleteFromLinkedList(struct Node *p, int pos)
{
    struct Node *q = NULL;
    int i, data;

    if(pos == 1)
    {
        q = first;
        data = first -> data;
        first = q -> Next;
        q -> Next = NULL;
        free(q);
        return data;
    }
    else if(pos > 0)
    {
        q = first;
        for(i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p -> Next;
        }
        if(p != NULL)
        {
            q -> Next = p -> Next;
            data = p -> data;
            p -> Next = NULL;
            free(p);
            return data;
        }
        else
        {
            printf("\nPosition is greater than number of nodes!");
        }
    }
    else
    {
        printf("\nPlease enter valid position!");
    }
    return -1;
}
int main()
{
    int A[] = {10, 14, 17, 20, 35};
    int pos, res;
    Create(A, 5);
    printf("\nBefore deleting: ");
    Display(first);
    printf("\nEnter position: ");
    scanf("%d", &pos);
    res = DeleteFromLinkedList(first, pos);
    if(res != -1)
        printf("\n%d is deleted from the Linked List!", res);
    printf("\nAfter delete operation: ");
    Display(first);
    return 0;
}