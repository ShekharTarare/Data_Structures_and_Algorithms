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
int CheckingLinkedListIsSorted(struct Node *p)
{
    int x;
    x = p -> data; //assigning data of first node
    while(p != NULL) //running till last node
    {
        if(x > p -> data) //checking previous is greater than next node
            return 0; //If greater then not sorted
        x = p -> data; //else pass the data to x for next comparison
        p = p -> Next; //Shifting to next node
    }
    return 1; //sorted
}
int main()
{
    int A[] = {3, 7, 9, 10, 4}, res;
    Create(A, 5);
    Display(first);
    res = CheckingLinkedListIsSorted(first);
    if(res == 1)
        printf("\nSorted!");
    else    
        printf("\nNot sorted!");
    return 0; 
}