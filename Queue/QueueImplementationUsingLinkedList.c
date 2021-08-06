#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *Next;
}*front = NULL, *rear = NULL;
void Enqueue(int data)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL)
        printf("\nQueue is full!");
    else
    {
        t -> data = data;
        t -> Next = NULL;
        if(front == NULL)
            front = rear = t;
        else
        {
            rear -> Next = t;
            rear = t;
        }
    }
}
int Dequeue()
{
    int x = -1;
    struct Node *q;
    if(front == NULL)
        printf("\nQueue is empty!");
    else
    {
        q = front;
        front = front -> Next;
        x = q -> data;
        free(q);
    }
    return x;
}
void Display()
{
    struct Node *p;
    p = front;
    printf("\nThe elements are: ");
    while(p != NULL)
    {
        printf("%d ", p -> data);
        p = p ->Next;
    }
}
int main()
{
    int res;
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    printf("\nBefore deletion: ");
    Display();
    res = Dequeue();
    if(res != -1)
        printf("\n%d is deleted!", res);
    printf("\nAfter deletion: ");
    Display();
    Enqueue(40);
    Enqueue(50);
    Display();
    return 0;
}