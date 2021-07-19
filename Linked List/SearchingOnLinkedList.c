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
    first = (struct Node*)malloc(n*sizeof(struct Node));
    first -> Next = NULL;
    first -> data = A[0];
    last = first;

    for(i = 1; i < n; i++)
    {
        t = (struct Node*)malloc(n*sizeof(struct Node));
        t -> Next = NULL;
        t -> data = A[i];
        last -> Next = t;
        last = t;
    }
}
struct Node* Search(struct Node *p, int key)
{
    while(p != NULL)
    {
        if(key == p -> data)
            return p;
        p = p -> Next;
    }
    return NULL;
}
struct Node* SearchUsingRecursion(struct Node *p, int key)
{
    if(p == NULL)
        return NULL;
    if(key == p -> data)
        return p;
    return SearchUsingRecursion(p -> Next, key);
}
struct Node* Search_Improved(struct Node *p, int key)
{
    struct Node *q = NULL; //temporary node, it will point to the previous node of the node where key will be there
    while(p != NULL) //traverse till end
    {
        if(key == p -> data) //if key == data
        {
            if(p != first) //if it is not the first node
            {
                q -> Next = p -> Next; //passing address of next of p to next of q, q will point to the next node after p
                p -> Next = first; //p will become first node and will pass the address of the first node to the next of p
            }
            first = p; //make first point to p
            return p;
        }
        else
        {
            q = p; //make q point to node where q is pointing
            p = p -> Next; //make node point on the next node
        }
    }
    return NULL; //else return NULL
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    struct Node *res, *resRec, *imp;
    Create(A, 5);
    res = Search(first, 0);   
    resRec = SearchUsingRecursion(first, 3); 
    imp = Search_Improved(first, 4);
    if(res != NULL)
        printf("\nKey found using Iterative!");
    else
        printf("\nKey not found using Iterative!");
    
    if(resRec != NULL)
        printf("\nKey found using Recursion!");
    else
        printf("\nKey not found using Recursion!");

    if(imp != NULL)
        printf("\nKey found from Improved!");
    else    
        printf("\nKey not found from Improved!");
    return 0;
}