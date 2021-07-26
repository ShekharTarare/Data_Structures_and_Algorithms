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
int Delete(struct Node *p, int pos)
{
    struct Node *q = NULL;
    int i, data;
    if(pos == 0) 
    {
        if(Head == NULL) //if list is empty
            return -1;
        else 
        {
            p = q = Head; 
            while(p -> Next != Head) //traverse till end
                p = p -> Next;
            if(p == Head) //if only 1 node
            {
                data = Head -> data;
                free(Head);
                Head = NULL;
                return data;
            }
            else
            {
                Head = q -> Next;
                data = q -> data;
                p -> Next = Head;
                q -> Next = NULL;
                free(q);
                return data;
            }
        }
    }
    else if(pos > 0)
    {
        for(i = 0; i < pos; i++)
        {
            q = p;
            p = p -> Next;
        }
        data = p -> data;
        q -> Next = p -> Next;
        p -> Next = NULL;
        free(p);
        return data;
    }
    else
    {
        printf("\nInvalid position! ");
    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5}, res;
    Create(A, 5);
    printf("\nBefore Delete: \n");
    Display(Head);
    res = Delete(Head, 1);
    if(res == -1)
    {
        printf("\nNo nodes deleted! \n");
    }
    else
    {
        printf("\n%d is deleted from linked list!\n", res);
    }
    printf("\nAfter Delete: \n");
    Display(Head);
    return 0;
}