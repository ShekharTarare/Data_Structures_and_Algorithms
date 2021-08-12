#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
    struct TreeNode *lChild;
    int data;
    struct TreeNode *rChild;
}*root = NULL;
struct Queue //to store addresses of nodes
{
    int size;
    int front;
    int rear;
    struct TreeNode **Q; //Because it is a dynamic queue which is going to store adresses of nodes
};
void CreateQueue(struct Queue *q, int size)
{
    q -> size = size;
    q -> front = q -> rear = -1;
    q -> Q = (struct TreeNode **)malloc(size*sizeof(struct TreeNode *));
}
void Enqueue(struct Queue *q, struct TreeNode *data)
{
    if((q -> rear + 1) % q -> size == q -> front)
        printf("\nQueue is full!");
    else
    {
        q -> rear = (q -> rear + 1) % q -> size;
        q -> Q[q -> rear] = data;
    }
}
struct TreeNode * Dequeue(struct Queue *q)
{
    struct TreeNode* x = NULL;
    if(q -> rear == q -> front)
        printf("\nQueue is empty!");
    else
    {
        q -> front = (q -> front + 1) % q -> size;
        x = q -> Q[q -> front];
    }
    return x;
}
int IsEmpty(struct Queue q)
{
    return q.front == q.rear;
}
void CreateTree()
{
    struct TreeNode *p, *t;
    int x;
    struct Queue q;
    CreateQueue(&q, 100);

    printf("\nEnter root value: ");
    scanf("%d", &x);
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root -> data = x;
    root -> lChild = root -> rChild = NULL;
    Enqueue(&q, root);

    while(!IsEmpty(q))
    {
        p = Dequeue(&q);
        printf("\nEnter left child of %d: ", p -> data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            t -> data = x;
            t -> lChild = t -> rChild = NULL;
            p -> lChild = t;
            Enqueue(&q, t);
        }
        printf("\nEnter right child of %d: ", p -> data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            t -> data = x;
            t -> lChild = t-> rChild = NULL;
            p -> rChild = t;
            Enqueue(&q, t);
        }
    }
}

void PreOrder(struct TreeNode *p)
{
    if(p)
    {
        printf("%d ", p -> data);
        PreOrder(p -> lChild);
        PreOrder(p -> rChild);
    }
}
void InOrder(struct TreeNode *p)
{
    if(p)
    {
        InOrder(p -> lChild);
        printf("%d ", p -> data);
        InOrder(p -> rChild);
    }
}
void PostOrder(struct TreeNode *p)
{
    if(p)
    {
        PostOrder(p -> lChild);
        PostOrder(p -> rChild);
        printf("%d ", p -> data);
    }
}
int main()
{
    CreateTree();
    printf("\nPreOrder: ");
    PreOrder(root);
    printf("\nInOrder: ");
    InOrder(root);
    printf("\nPostOrder: ");
    PostOrder(root);
    return 0;
}