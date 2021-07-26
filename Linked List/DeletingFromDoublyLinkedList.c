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
int Delete(struct Node *p, int pos)
{
    int i, data;
    if(pos == 1)
    {
        if(first == NULL)
        {
            return -1;
        }
        else if(first -> Next == NULL)
        {
            data = first -> data;
            first = NULL;
            return data;
        }
        else
        {
            p = first;
            first = p -> Next;
            data = p -> data;
            p -> Next -> Prev = NULL;
            free(p);
            return data;
        }
    }
    else if(pos > 1)
    {
        for(i = 0; i < pos - 1; i++)
            p = p -> Next;
        if(p != NULL)
        {
            p -> Prev -> Next = p -> Next;
            if(p -> Next != NULL)
                p -> Next -> Prev = p -> Prev;
            data = p -> data;
            free(p);
            return data;
        }
        else
        {
            printf("\nPosition is greater than number of nodes!\n");
        }
    }
    else
    {
        printf("\nInvalid position!\n");
    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5}, data, pos, res;
    Create(A, 5);
    printf("\nEnter the position: ");
    scanf("%d", &pos);
    printf("\nBefore Deletion: ");
    Display(first);
    res = Delete(first, pos);
    if(res != -1)
    {
        printf("\n%d deleted!\n", res);
    }
    else
    {
        printf("\nEmpty linked list!\n");
    }
    printf("\nAfter Deletion: ");
    Display(first);
    return 0;
}