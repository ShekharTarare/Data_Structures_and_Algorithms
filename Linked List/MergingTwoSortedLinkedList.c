#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *Next;
}*first = NULL, *second = NULL, *third = NULL; //third will point to the first node of merged linked list 
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
void MergeTwoSortedLinkedList(struct Node *f, struct Node *s)
{
    struct Node *last; //point to the last node of merged linked list
    if(f -> data > s -> data) //if data at first node is greater than second
    {
        third = last = s; //third and last will point to first node of second linked list
        s = s -> Next; //s will shift to next node
        last -> Next = NULL; //NULL at the link section of last
    }
    else
    {
        third = last = f;
        f = f -> Next;
        last -> Next = NULL;
    }

    while(f != NULL && s != NULL) //traversing both linked list
    {
        if(f -> data > s -> data) //If data at first is greater
        {
            last -> Next = s; //address of the node where s is pointing will store at last -> Next
            last = s; //last will come to the node where s is pointing
            s = s -> Next;  //shift to next node
            last -> Next = NULL; //NULL at last -> Next
        }
        else
        {
            last -> Next = f;
            last = f;
            f = f -> Next;
            last -> Next = NULL;
        }
    }

    if(f != NULL) //If incase the last node missed
        last -> Next = f; //connecting the last node with the merged linked list
    else
        last -> Next = s;
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
    printf("After Merging: \n");
    MergeTwoSortedLinkedList(first, second);
    display(third);
    return 0;
}