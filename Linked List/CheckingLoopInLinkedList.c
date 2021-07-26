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
    last -> Next = first -> Next; //for making a loop
}
int CheckingLoop(struct Node *f)
{
    struct Node *q, *p;
    p = q = f; //point to first node
    do
    {
        p = p -> Next; //shift to next node
        q = q -> Next; //shift to next node
        q = q != NULL ? q -> Next : NULL; //Again shift but check whether Next is NULL if it is then store NULL else shift
    } while (p != NULL && q != NULL && p != q); //check both p and q are NULL and also p == q
    return p == q ? 1 : 0; //if p == q then loop else not loop
}
int main()
{
    int A[] = {1, 2, 3, 4, 5}, res;
    Create(A, 5);
    res = CheckingLoop(first);
    res == 1 ? printf("\nLoop!") : printf("\nNot a Loop!");
    return 0;
}