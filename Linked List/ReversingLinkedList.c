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
int count(struct Node *p)
{
    int len = 0;
    while(p != NULL)
    {
        len++;
        p = p -> Next; 
    }
    return len;
}
void ReverseUsingAnArray(struct Node *p)
{
    int *Arr, i = 0;
    struct Node *q;
    Arr = (int *)malloc(count(p)*sizeof(int)); //dynamic array, can use normal array also
    q = p; //q points to first node
    while(q != NULL) //run till last node
    {
        Arr[i] = q -> data; //transfer data to array
        q = q -> Next;  //shift to next node
        i++; //increment index
    }
    q = p; //again starting from fist node
    i--; //decreasing index by 1 because on the previous while loop 1 extra was added at the last step
    while(q != NULL) //run till last
    {
        q -> data = Arr[i]; //giving back the values but from the last index 
        q = q -> Next; //shifting to next node
        i--; //decreasing index
    }
}
void ReverseUsingSlidingPointers(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    int i;

    while(p != NULL)
    {
        r = q;
        q = p;
        p = p -> Next;
        q -> Next = r;
    }
    first = q;
}
void ReverseUsingRecursion(struct Node *p, struct Node *q)
{
    if(p != NULL)
    {
        ReverseUsingRecursion(p -> Next, p);
        p -> Next = q;
    }
    else
        first = q;
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    Create(A, 5);
    printf("\nBefore Reverse using Array operation: ");
    Display(first);
    ReverseUsingAnArray(first);
    printf("\nAfter Reverse using Array operation: ");
    Display(first);

    printf("\nBefore Reverse using sliding pointers operation: ");
    Display(first);
    ReverseUsingSlidingPointers(first);
    printf("\nAfter Reverse using sliding pointers operation: ");
    Display(first);

    printf("\nBefore Reverse using Recursion operation: ");
    Display(first);
    ReverseUsingRecursion(first, NULL);
    printf("\nAfter Reverse using Recursion operation: ");
    Display(first);
    return 0;
}