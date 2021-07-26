#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *Next;
}*Head = NULL;
void Create(int A[], int size)
{
    struct Node *t, *last;
    int i;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head -> data = A[0];
    Head -> Next = Head;
    last = Head;

    for(i = 1; i < size; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> Next = last -> Next;
        last -> Next = t;
        last = t;
    }
}
void Display(struct Node *p)
{
    do
    {
        printf("%d ", p -> data);
        p = p -> Next;
    }while(p != Head);
}
void Insert(struct Node *p, int data, int pos)
{
    struct Node *t;
    int i;
    if(pos == 0) //if at first position
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = data;

        if(Head == NULL) //If no nodes available
        {
            Head = t; //make t as first node
            Head -> Next = Head; //make it as circular node
        }
        else //if having nodes
        {
            p = Head; //p will point to head
            while(p -> Next != Head) //run till we get the last node
                p = p -> Next;
            t -> Next = Head; //make t as first node
            Head = t; //storing t's address on head
            p -> Next = Head; //last node will point to new first node i.e. t
        }
    }
    else if(pos > 0) //for position greater than 0
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = data;
        for(i = 0; i < pos - 1; i++) //till we get the node lesser than the position
            p = p -> Next;
        t -> Next = p -> Next; //change the address and make it to point on t
        p -> Next = t; 
    }
    else
    {
        printf("\nInvalid position!");
    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    Create(A, 5);
    printf("\nBefore Insert: \n");
    Display(Head);
    printf("\nAfter insert: \n");
    Insert(Head, 6, 4);
    Display(Head);
    return 0;
}