#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *Next;
}*top = NULL;
void Create(int A[], int size)
{
    struct Node *t, *last;
    int i;
    top = (struct Node *)malloc(sizeof(struct Node));
    top -> data = A[0];
    top -> Next = NULL;
    last = top;

    for(i = 1; i < size; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> Next = NULL;
        last -> Next = t;
        last = t;
    }
}
void Display()
{
    struct Node *t;
    t = top;
    printf("\nThe elements are: ");
    while(t != NULL)
    {
        printf("%d ", t -> data);
        t = t -> Next;
    }
}
void Push(int data)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t -> data = data;
    if(t == NULL)
        printf("\nStack overflow!\n");
    else
    {
        t -> Next = top;
        top = t;
    }
}
int Pop()
{
    struct Node *st;
    int x = -1;
    if(top == NULL)
        return x;
    else
    {
        st = top;
        x = st -> data;
        top = st -> Next;
        free(st);
    }
    return x;
}
int Peek(int pos)
{
    struct Node *st;
    int i;
    st = top;
    for(i = 0; i < pos - 1; i++)
        st = st -> Next;
    if(st != NULL && pos != 0)
        return st -> data;
    else 
        return -1;
}
int StackTop()
{
    if(top == NULL)
        return -1;
    else    
        return top -> data;
}
int IsEmpty()
{
    if(top == NULL)
        return 1;
    else
        return 0;
}       
int IsFull()
{
    int r;
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL)
        r = 1;
    else
        r = 0;
    free(t);
    return r;
}
int main()
{
    int i, ch, data, pos, res;
    int A[] = {1, 2, 3, 4, 5};
    Create(A, 5);
    while(ch != 8)
    {
        printf("\nChoose from the below menu: \n1. Display \n2. Push \n3. Pop \n4. Peek \n5. Stack top \n6. IsEmpty \n7. IsFull \n8. Exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: Display();
                    break;

            case 2: printf("\nEnter the data to insert: ");
                    scanf("%d", &data);
                    Push(data);
                    Display(top);
                    break;

            case 3: res = Pop();
                    if(res == -1)
                        printf("\nFailed to delete!\n");
                    else
                        printf("\n%d deleted from stack!\n", res);
                    Display(top);
                    break;

            case 4: printf("\nEnter the position: ");
                    scanf("%d", &pos);
                    res = Peek(pos);
                    if(res == -1)
                        printf("\nFailed to show!\n");
                    else
                        printf("\n%d is available at %d!\n", res, pos);
                    break;

            case 5: res = StackTop();
                    if(res == -1)
                        printf("\nFailed to show!\n");
                    else
                        printf("\n%d is available at top!\n", res);
                    break;

            case 6: res = IsEmpty();
                    if(res == 1)
                        printf("\nStack is empty!\n");
                    else
                        printf("\nStack is not empty!\n");
                    break;

            case 7: res = IsFull();
                    if(res == 1)
                        printf("\nStack is Full!\n");
                    else
                        printf("\nStack is not Full!\n");
                    break;

            case 8: exit(1);

            default: printf("\nInvalid option!\n");
        }
    }
    return 0;
}