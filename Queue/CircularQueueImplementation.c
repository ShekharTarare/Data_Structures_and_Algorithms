#include<stdio.h>
#include<stdlib.h>
struct Queue 
{
    int size;
    int front;
    int rear;
    int *p;
};
void Create(struct Queue *q, int size)
{
    q -> size = size;
    q -> front = q -> rear = 0;
    q -> p = (int *)malloc(q -> size*sizeof(int));
}
void Enqueue(struct Queue *q, int data)
{
    if((q -> rear + 1) % q -> size == q -> front)
        printf("\nQueue is full!");
    else
    {
        q -> rear = (q -> rear + 1) % q -> size;
        q -> p[q -> rear] = data;
    }
}
int Dequeue(struct Queue *q)
{
    int x = -1;
    if(q -> front == q -> rear)
        printf("\nQueue is empty!");
    else
    {
        q -> front = (q -> front + 1) % q -> size;
        x = q -> p[q -> front];
    }
    return x;
}
void Display(struct Queue q)
{
    int i;
    printf("\nThe elements are: ");
    i = q.front + 1;
    do
    {
        printf("%d ", q.p[i]);
        i = (i + 1) % q.size;
    }while(i != (q.rear + 1) % q.size);
}
int main()
{
    struct Queue q;
    int res;
    Create(&q, 5);
    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    Enqueue(&q, 40);
    Enqueue(&q, 50);
    printf("\nBefore deletion: ");
    Display(q);
    res = Dequeue(&q);
    if(res != -1)
        printf("\n%d is deleted!", res);
    printf("\nAfter deletion: ");
    Display(q);
    Enqueue(&q, 60);
    Display(q);
    return 0;
}