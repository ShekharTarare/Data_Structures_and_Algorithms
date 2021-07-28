#include<Stdio.h>
#include<stdlib.h>
struct Stack 
{
    int size;
    int top;
    int *s;
};
void Display(struct Stack st)
{
    int i;
    if(st.top == -1)
        printf("\nStack underflow");
    else
    {
        printf("\nThe elements are: ");
        for(i = st.top; i >= 0 ; i--)
        {
            printf("%d ", st.s[i]);
        }
    }
}
void Push(struct Stack *st, int data)
{
    if(st -> top == st -> size - 1)
        printf("\nStack Overflow!\n");
    else
    {
        st -> top++;
        st -> s[st -> top] = data;
    }
}
int Pop(struct Stack *st)
{
    int x = -1;
    if(st -> top == -1)
        return x;
    else
    {
        x = st -> s[st -> top];
        st -> top--;
        return x;
    }
}
int Peek(struct Stack st, int pos)
{
    int x = -1;
    if((st.top - pos) + 1 < 0)
        return x;
    else
    {
        x = st.s[(st.top - pos) + 1];
        return x;
    }
}
int StackTop(struct Stack st)
{
    int x = -1;
    if(st.top == -1)
        return x;
    else
    {
        x = st.s[st.top];
        return x;
    }        
}
int IsEmpty(struct Stack st)
{
    if(st.top == -1)
        return 1;
    else    
        return 0;
}
int IsFull(struct Stack st)
{
    if(st.top == st.size - 1)
        return 1;
    else
        return 0;
}
int main()
{
    struct Stack st;
    int i, ch, data, pos, res;
    printf("\nEnter size of an array: ");
    scanf("%d", &st.size);
    st.s = (int *)malloc(st.size*sizeof(int));
    st.top = -1;
    printf("\nEnter %d elements: ", st.size);
    for(i = 0; i < st.size; i++)
    {
        scanf("%d", &st.s[i]);
        st.top++;
    }
    while(ch != 8)
    {
        printf("\nChoose from the below menu: \n1. Display \n2. Push \n3. Pop \n4. Peek \n5. Stack top \n6. IsEmpty \n7. IsFull \n8. Exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: Display(st);
                    break;

            case 2: printf("\nEnter the data to insert: ");
                    scanf("%d", &data);
                    Push(&st, data);
                    Display(st);
                    break;

            case 3: res = Pop(&st);
                    if(res == -1)
                        printf("\nFailed to delete!\n");
                    else
                        printf("\n%d deleted from stack!\n", res);
                    Display(st);
                    break;

            case 4: printf("\nEnter the position: ");
                    scanf("%d", &pos);
                    res = Peek(st, pos);
                    if(res == -1)
                        printf("\nFailed to show!\n");
                    else
                        printf("\n%d is available at %d!\n", res, pos);
                    break;

            case 5: res = StackTop(st);
                    if(res == -1)
                        printf("\nFailed to show!\n");
                    else
                        printf("\n%d is available at top!\n", res);
                    break;

            case 6: res = IsEmpty(st);
                    if(res == 1)
                        printf("\nStack is empty!\n");
                    else
                        printf("\nStack is not empty!\n");
                    break;

            case 7: res = IsFull(st);
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