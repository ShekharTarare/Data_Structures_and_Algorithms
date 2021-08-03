#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    char data;
    struct Stack *Next;
}*top = NULL;
int Length(char *inp)
{
    int len;
    for(len = 0; inp[len] != '\0'; len++);
    return len;
}
void Push(char data)
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
char *InfixToPostfix(char *inp)
{
    int i = 0, j = 0;
    char *postfix;
    postfix = (char *)malloc((Length(inp) + 2)*sizeof(char)); //extra 2 for \0 and $ which we have inserted initially
    while(inp[i] != '\0')
    {
        if(IsOperand(inp[i]))
            postfix[j++] = inp[i++];
        else
        {
            if(Pre(inp[i]) > Pre(top -> data))
                Push(inp[i++]);
            else
                postfix[j++] = Pop();
        }
    }
    while(top != NULL)
        postfix[j++] = Pop();
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char *res;
    Push('$');
    char *inp = "a+b*c-d/e"; //or char inp[]
    res = InfixToPostfix(inp);
    printf("%s", res);
    return 0;
}