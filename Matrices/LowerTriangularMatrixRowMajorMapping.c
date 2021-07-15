#include<stdio.h>
#include<stdlib.h>
struct Array
{
    int *A;
    int size;
};
int Get(struct Array a, int i, int j)
{
    if(i >= j)
        return a.A[(i*(i-1)/2) +(j-1)];
    else
        return 0;
}
void Set(struct Array *a, int i, int j, int x)
{
    if(i >= j)
        a->A[(i*(i-1)/2) +(j-1)] = x;
}
void Display(struct Array a)
{
    int i, j;
    for(i = 1; i <= a.size; i++)
    {
        for(j = 1; j <= a.size; j++)
        {
            if(i >= j)
                printf("%d ", a.A[(i*(i-1)/2) +(j-1)]);
            else
                printf("%d ", 0);
        }
        printf("\n");
    }
}
int main()
{
    struct Array a;
    int i, j, x;
    printf("\nEnter the dimension of an array: ");
    scanf("%d", &a.size);
    a.A = (int *)malloc(a.size*(a.size + 1) / 2 * sizeof(int));

    printf("\nEnter array elements: ");

    for(i = 1; i <= a.size; i++)
    {
        for(j = 1; j <= a.size; j++)
        {
            scanf("%d", &x);
            Set(&a, i, j, x);
        }
    }

    Display(a);

    printf("\n%d\n", Get(a, 2, 2));
    printf("\n%d\n", Get(a, 2, 3));
    return 0;
}