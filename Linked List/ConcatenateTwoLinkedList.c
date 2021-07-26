#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *Next;
}*first = NULL, *second = NULL;
void Create(int A[], int B[], int size1, int size2)
{
    struct Node *t1, *t2, *last1, *last2;
    int i;
    first = (struct Node*)malloc(sizeof(struct Node));
    first -> Next = NULL;
    first -> data = A[0];
    last1 = first;

    for(i = 1; i < size1; i++)
    {
        t1 = (struct Node*)malloc(sizeof(struct Node));
        t1 -> Next = NULL;
        t1 -> data = A[i];
        last1 -> Next = t1;
        last1 = t1;
    }

    second = (struct Node*)malloc(sizeof(struct Node));
    second -> Next = NULL;
    second -> data = B[0];
    last2 = second;

    for(i = 1; i < size2; i++)
    {
        t2 = (struct Node*)malloc(sizeof(struct Node));
        t2 -> Next = NULL;
        t2 -> data = B[i];
        last2 -> Next = t2;
        last2 = t2;
    }
}
void display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p -> data);
        p = p -> Next;
    }
}
void ConcatTwoLinkedList(struct Node *p, struct Node *q)
{
    while(p -> Next != NULL) //till last node
    {
        p = p -> Next;
    }
    p -> Next = q; //join the second linked list by passing the address ofsecond linked list to the link section of last node
}
int main()
{
    int A[] = {2, 4, 8, 9, 18};
    int B[] = {3, 7, 10, 11, 20};
    Create(A, B, 5, 5);
    printf("First Linked list: \n");
    display(first);
    printf("\n\n");
    printf("Second Linked list: \n");
    display(second);
    printf("\n\n");
    printf("After Concatenation: \n");
    ConcatTwoLinkedList(first, second);
    display(first); 
    return 0;
}