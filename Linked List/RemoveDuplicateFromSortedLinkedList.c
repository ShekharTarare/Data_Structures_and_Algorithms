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
    first = (struct Node*)malloc(sizeof(struct Node));
    first -> Next = NULL;
    first -> data = A[0];
    last = first;

    for(i = 1; i < size; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t -> Next = NULL;
        t -> data = A[i];
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
void RemoveDuplicate(struct Node *p)
{
    struct Node *q;
    q = first; //point on first node
    p = first -> Next; //point on second node
    while(p != NULL) //till last node
    {
        if(p -> data != q -> data) //If data of both doesn't match
        {
            q = p; //shift q to p
            p = p -> Next; //shift p to next node
        }
        else //If matches
        {
            q -> Next = p -> Next; //delete node where p is pointing
            p -> Next = NULL;
            free(p);
            p = q -> Next; //then assign p to next node
        }
    }
}
int main()
{
    int A[] = {3, 7, 9, 10, 10, 11, 12, 12, 14, 14}, res;
    Create(A, 10);
    printf("\nBefore removal: ");
    Display(first);
    RemoveDuplicate(first);
    printf("\nAfter removal: ");
    Display(first);
    return 0; 
}