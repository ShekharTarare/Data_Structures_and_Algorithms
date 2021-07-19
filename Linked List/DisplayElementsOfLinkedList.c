#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    int data; //for storing data
    struct Node *Next; //self referential structure (for storing the address of next node)
}*first = NULL; //Declaring and assigning NULL to the first pointer globally 
void Create(int A[], int size)
{
    struct Node *t, *last; //t will act as temporary node, last will help in remembering the previous node
    int i;
    first = (struct Node*)malloc(size*sizeof(struct Node)); //creating node in heap
    first -> data = A[0]; //assigning first data to data section of node
    first -> Next = NULL; //storing null in the link section of first
    last = first; //storing the address of first to last, Now the last will point to the node where first is pointing

    for(i = 1; i < size; i++)
    {
        t = (struct Node*)malloc(size*sizeof(struct Node)); //This is a new node
        t -> Next = NULL; //next will be NULL
        t -> data = A[i]; //Storing the data in the data part
        last -> Next = t; //passing the address of new node to Next of last
        last = t; //Here the last will point to new node
    }
}
void Display(struct Node *n)
{
    while(n != NULL) //If we'll write n -> Next instead of n then it will print only 4 out of 5 data
    {
        printf("%d ", n -> data);
        n = n -> Next; //Go to the next node
    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    Create(A, 5);

    Display(first);

    return 0;
}