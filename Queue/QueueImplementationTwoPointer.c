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
    q -> front = q -> rear = -1;
    q -> p = (int *)malloc(size*sizeof(int));
}
void Enqueue(struct Queue *q, int data)
{
    if(q -> rear == q -> size - 1)
        printf("\nQueue is full!");
    else
    {
        q -> rear++;
        q -> p[q -> rear] = data;
    }
}
int Dequeue(struct Queue *q)
{
    int x = -1;
    if(q -> rear != q -> front)
    {
        q -> front++;
        x = q -> p[q -> front];
    }
    return x;
}
void Display(struct Queue q)
{
    int i;
    if(q.front != q.rear)
    {
        printf("\nThe elements are: ");
        for(i = q.front + 1; i <= q.rear; i++)
        {
            printf("%d ", q.p[i]);
        }
    }
    else
        printf("\nQueue is empty!");
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
    Enqueue(&q, 60);
    printf("\nBefore deletion: ");
    Display(q);
    res = Dequeue(&q);
    if(res != -1)
        printf("\n%d deleted!", res);
    else
        printf("\nStack is empty!");
    printf("\nAfter deletion: ");
    Display(q);
    return 0;
}