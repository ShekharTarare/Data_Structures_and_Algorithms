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
    first -> Prev = first;
    first -> Next = first;
    last = first;

    for(i = 1; i < size; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> Prev = last;
        t -> Next = first;
        last -> Next = t;
        last = t;
    }
    first -> Prev = last;
}
void display(struct Node *p)
{
    do
    {
        printf("%d ", p -> data);
        p = p -> Next;
    }while(p != first);
}
int Count(struct Node *p)
{
    int length = 0;
    do
    {
        length++;
        p = p -> Next;
    }while(p != first);
    return length;
}
void Insert(struct Node *p, int data, int pos)
{
    struct Node *t;
    int i;
    if(pos < 0 || Count(p) < pos)
        printf("\nInvalid position!\n");
    else if(pos == 1)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = data;
        t -> Next = t -> Prev = t;
        if(first == NULL)
            first = t;
        else if(first -> Next == first)
        {
            t -> Prev = first;
            t -> Next = first;
            first -> Next = t;
            first -> Prev = t;
            first = t;
        }
        else
        {
            t -> Prev = first -> Prev;
            t -> Next = first;
            first -> Prev -> Next = t;
            first -> Prev = t;
            first = t;
        }
    }
    else
    {
        for(i = 0; i < pos - 2; i++)
            p = p -> Next;
        if(p == NULL)
            printf("\nPosition cannot be greater than number of nodes!\n");
        else
        {            
            t = (struct Node *)malloc(sizeof(struct Node));
            t -> data = data;
            t -> Next = t -> Prev = t;
            t -> Prev = p;
            t -> Next = p -> Next;
            p -> Next -> Prev = t;
            p -> Next = t;
        }
    }
}
int Delete(struct Node *p, int pos)
{
    int data, i;
    if(pos < 0 || Count(p) < pos)
        return -1;
    else if(pos == 1)
    {
        if(first == NULL)
            return -1;
        else if(p -> Next == first)
        {
            data = p -> data;
            first = NULL;
            free(p);
            return data;
        }
        else
        {
            data = p -> data;
            p -> Next -> Prev = p -> Prev;
            p -> Prev -> Next = p -> Next;
            first = p -> Next;
            free(p);
            return data;
        }
    }
    else
    {
        for(i = 0; i < pos - 1; i++)
            p = p -> Next;
        data = p -> data;
        p -> Next -> Prev = p -> Prev;
        p -> Prev -> Next = p -> Next;
        free(p);
        return data;
    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5}, res;
    Create(A, 5);
    
    printf("\nBefore Insertion: \n");
    display(first);
    Insert(first, 6, 3);
    printf("\nAfter Insertion: \n");
    display(first);

    printf("\nBefore Deletion: \n");
    display(first);
    res = Delete(first, 7);
    if(res == -1)
        printf("\nInvalid position!\n");
    else
        printf("\n%d deleted!\n", res);
    printf("\nAfter Deletion: \n");
    display(first);
    return 0;
}