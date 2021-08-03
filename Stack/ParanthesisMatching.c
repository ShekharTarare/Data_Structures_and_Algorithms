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
void Pop()
{
    struct Stack *t;
    t = top;
    if(t == NULL)
        printf("\nStack underflow!");
    else
    {
        top = t -> Next;
        free(t);
    }
}
int CheckParantheses(char *inp)
{
    int i;
    for(i = 0; i < Length(inp); i++)
    {
        if(inp[i] == '(' || inp[i] == '[' || inp[i] == '{')
            Push(inp[i]);
        else if(inp[i] == ')' || inp[i] == ']' || inp[i] == '}')
        {
            if(top == NULL)
                return 0;
            Pop();
        }
    }
    return top == NULL ? 1 : 0;
}
int main()
{
    int res;
    char *inp = "{(a+b)[((a*b)*c)]}"; //or char inp[]
    res = CheckParantheses(inp);
    if(res == 1)
        printf("\nParanthesis are balanced!");
    else
        printf("\nParanthesis are not balanced!");
    return 0;
}