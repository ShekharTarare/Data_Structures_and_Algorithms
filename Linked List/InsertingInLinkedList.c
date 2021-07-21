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
    first = (struct Node*)malloc(sizeof(struct Node));
    first -> Next = NULL;
    first -> data = A[0];
    last = first;

    for(i = 1; i < n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> Next = NULL;
        last -> Next = t;
        last = t;
    }
}
void Insert(struct Node *p, int pos, int x)
{
    struct Node *t;
    int i;
    t = (struct Node*)malloc(sizeof(struct Node));
    t -> data = x;
    if(pos == 0)
    {
        t -> Next = first;
        first = t;
    }
    else if(pos > 0)
    {
        for(i = 0; i < pos - 1; i++)
        {
            p = p -> Next;
        }
        if(p != NULL)
        {
            t -> Next = p -> Next;
            p -> Next = t;
        }
        else
        {
            printf("\nPosition is greater than number of Nodes!");
        }
    }
    else
    {
        printf("\nPlease enter valid position!");
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
    int pos, data;
    Create(A, 5);

    printf("\nEnter the position where you want to insert: ");
    scanf("%d", &pos);
    printf("\nEnter the data: ");
    scanf("%d", &data);
    Insert(first, pos, data);

    printf("\nThe elements are: ");
    Display(first);
    return 0;
}