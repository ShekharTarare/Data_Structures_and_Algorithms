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
    first -> data = A[0];
    first -> Next = NULL;
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
void DisplayFromLeftToRight(struct Node *p)
{
    if(p != NULL)
    {
        printf("%d ", p -> data);
        DisplayFromLeftToRight(p -> Next);
    }
}
void DisplayFromRightToLeft(struct Node *p)
{
    if(p != NULL)
    {
        DisplayFromRightToLeft(p -> Next);
        printf("%d ", p -> data);
    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    Create(A, 5);
    printf("\nFrom Left to Right: \n");
    DisplayFromLeftToRight(first);
    printf("\nFrom Right to Left: \n");
    DisplayFromRightToLeft(first);
    return 0;
}