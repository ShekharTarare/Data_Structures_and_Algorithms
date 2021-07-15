#include<stdio.h>
struct ArrayDet
{
    int OneDArray[5];
    int size;
};
int Get(struct ArrayDet a, int i, int j)
{
    if(i == j)
        return a.OneDArray[i - 1];
    else
        return 0;
}
void Set(struct ArrayDet *a, int i, int j, int inp)
{
    if(i == j)
    {
        a->OneDArray[i - 1] = inp;
    }
    else
        a->OneDArray[i - 1] = 0;
}
void Display(struct ArrayDet a)
{
    int i, j;
    for(i = 1; i <= a.size; i++)
    {
        for(j = 1; j <= a.size; j++)
        {
            if(i == j)
                printf("%d ", a.OneDArray[i - 1]);
            else
                printf("%d ", 0);
        }
        printf("\n");
    }
}
int main()
{
    struct ArrayDet a;
    a.size = 5;
    Set(&a, 1, 1, 5); Set(&a, 2, 2, 7); Set(&a, 3, 3, 9);
    Set(&a, 4, 4, 11); Set(&a, 5, 5, 13);
    Display(a);
    printf("\n%d\n", Get(a, 4, 4));
    printf("\n%d\n", Get(a, 4, 5));
    return 0;
}