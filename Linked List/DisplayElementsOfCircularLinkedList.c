#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    int data;
    struct Node *Next;
}*Head = NULL;
void Create(int A[], int size)
{
    struct Node *t, *last;
    int i;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head -> Next = Head; //point to itself, circular node
    Head -> data = A[0];
    last = Head;

    for(i = 1; i < size; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> Next = last -> Next; //the address of first node will be added to the Next of all nodes
        last -> Next = t;
        last = t;
    }
}
void Display(struct Node *p)
{
    do
    {
        printf("%d ", p -> data);
        p = p -> Next; 
    }while(p != Head && p != NULL); //run till head == p, used do while because using while
                                    //at first condition only it become true
}
void RecursiveDisplay(struct Node *p)
{
    static int flag = 0; //It will not lose value in the recursive calls
    if(p != Head || flag == 0) //checking head == p and flag, at first flag will be equal to zero and other condition will be false
    //So, it will get inside the if
    {
        flag = 1; //set as 1 and in the next call it will retain its value
        printf("%d ", p -> data);
        RecursiveDisplay(p -> Next);
    }
    flag = 0; //making it as 0 so that in the next call it will be 0 so that it will print
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    Create(A, 5);
    printf("\nOutput using normal function: \n");
    Display(Head);
    printf("\nOutput using Recursive function: \n");
    RecursiveDisplay(Head);
    return 0;
}