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
}
void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p -> data);
        p = p -> Next;
    }
}
void InsertInSorted(struct Node *p, int x)
{
    //q will be temporary pointer which will help in getting the previous node of the node where value needs to insert
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t -> data = x;
    t -> Next = NULL;
    if(p == NULL) //If no nodes
        first = t; //make the node where t is pointing as the first node
    else //If having nodes
    {
        if(p -> data > x) //if entered data is smaller than the first node's data means at first place node needs to insert
        {
            t -> Next = first; //pass the address stored in first to the t->Next, means making new node point to the first node
            first = t; ///make first point on the new node
        }
        else //If greater 
        {
            while(p -> data < x) //checking whether data is greater than any node data
            {
                if(p -> Next == NULL) //If none of the node data is greater then we can come out of the loop and insert at end
                {
                    break;
                }
                q = p; //shift q in place of p
                p = p -> Next; //shift p to next node
            }
            if(p -> Next == NULL) //If didn't find any data greater then the entered data
            {
                p -> Next = t; //make new node as the last node
            }
            else //If found
            {
                //p will be in node where data is greater than entered data, and q is at the previous node
                //we need to insert new node in between them
                t -> Next = q -> Next; //new node will point to node where p is there
                q -> Next = t; //The node where q is, now connected with the new node
            }
        }
    }
}
int main()
{
    int A[] = {10, 14, 17, 20, 35};
    int x;
    Create(A, 5);
    printf("\nEnter value to insert: ");
    scanf("%d", &x);
    InsertInSorted(first, x);

    printf("\nThe elements are: ");
    Display(first);
    return 0;
}