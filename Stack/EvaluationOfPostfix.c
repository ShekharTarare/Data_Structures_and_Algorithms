#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int data;
    struct Stack *Next;
}*top = NULL;
int Length(char *inp)
{
    int len;
    for(len = 0; inp[len] != '\0'; len++);
    return len;
}
void Push(int data)
{
    struct Stack *t;
    t = (struct Stack *)malloc(sizeof(struct Stack));
    t -> data = data;
    t -> Next = NULL;
    if(t == NULL)
        printf("\nStack overflow!");
    else
    {
        t -> Next = top;
        top = t;
    }
}
char Pop()
{
    int x = -1;
    struct Stack *t;
    t = top;
    if(t == NULL)
        printf("\nStack underflow!");
    else
    {
        x = top -> data;
        top = t -> Next;
        free(t);
    }
    return x;
}
int Pre(char inp)
{
    if(inp == '+' || inp == '-')
        return 1;
    else if(inp == '*' || inp == '/')
        return 2;
    else
        return 0;
}
int IsOperand(char inp)
{
    if(inp == '+' || inp == '-' || inp == '*' || inp == '/')
        return 0;
    else 
        return 1;
}
int Eval(char *postfix)
{
    int i=0;
    int x1,x2,r=0 ;

    for(i=0;postfix[i]!='\0';i++)
    {
        if(IsOperand(postfix[i]))
        {
            Push(postfix[i]-'0');
        }
        else
        {
            x2=Pop();x1=Pop();
            switch(postfix[i])
            {
                case '+':r=x1+x2; break;
                case '-':r=x1-x2; break;
                case '*':r=x1*x2; break;
                case '/':r=x1/x2; break;
            }
            Push(r);
        }
    }
    return top->data;
}
int main()
{
    char *postfix="35*62/+4-";
    printf("Result is %d\n",Eval(postfix));
    return 0;
}