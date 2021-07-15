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
        return a.A[a.size*(j-1)-(j-2)*(j-1)/2+i-j];
    else
        return 0;
}
void Set(struct Array *a, int i, int j, int x)
{
    if(i >= j)
        a->A[a->size*(j-1)-(j-2)*(j-1)/2+i-j]=x;
}
void Display(struct Array a)
{
    int i, j;
    for(i = 1; i <= a.size; i++)
    {
        for(j = 1; j <= a.size; j++)
        {
            if(i >= j)
                printf("%d ", a.A[a.size*(j-1)-(j-2)*(j-1)/2+i-j]);
            else
                printf("%d ", 0);
        }
        printf("\n");
    }
}
int main()
{
    struct Array a;
    a.A = (int *)malloc(a.size*(a.size + 1)/2 * sizeof(int));
    int x, i, j;
    printf("\nEnter the dimension: ");
    scanf("%d", &a.size);

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