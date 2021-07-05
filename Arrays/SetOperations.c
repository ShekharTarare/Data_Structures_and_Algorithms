#include<stdio.h>
void IntersectionForNonSortedArray(int A[], int B[])
{
    int i = 0, j, k = 0, flag = 0;
    int C[10];
    while(i < 5)
    {
        for(j = 0; j < 5; j++)
        {
            if(A[i] == B[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            C[k++] = A[i];
            flag = 0;
        }
        i++;
    }
    printf("\nIntersection for non sorted array: \n");
    for(i = 0; i < k; i++)
    {
        printf("%d\n", C[i]);
    }
}
void IntersectionForSortedArray(int C[], int D[])
{
    int i = 0, j = 0, k = 0;
    int E[10];

    while(i < 5 && j < 5)
    {
        if(C[i] > D[j])
        {
            if(C[i] == D[j])
            {
                E[k++] = C[i++];
                j++;
            }
            else
                j++;
        }
        else 
        {
            if(C[i] == D[j])
            {
                E[k++] = C[i++];
                j++;
            }
            else
                i++;
        }
    }
    printf("\nIntersection for sorted array: \n");
    for(i = 0; i < k; i++)
    {
        printf("%d\n", E[i]);
    }
}
void DifferenceForNonSortedArray(int A[], int B[])
{
    int i = 0, j = 0, k = 0, C[10], flag = 1;
    while(i < 5)
    {
        for(j = 0; j < 5; j++)
        {
            if(A[i] == B[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            C[k++] = A[i];
        }
        else
            flag = 1;
        i++;
    }
    printf("\nDifference for non sorted array: \n");
    for(i = 0; i < k; i++)
    {
        printf("%d\n", C[i]);
    }
}
void DifferenceForSortedArray(int C[], int D[])
{
    int i = 0, j = 0, k = 0, E[10];
    while(i < 5 && j < 5)
    {
        if(C[i] <= D[j])
        {
            if(C[i] != D[j])
            {
                E[k++] = C[i++];
            }
            else
                i++;
        }
        else
        {
            j++;
        }
    }
    printf("\nDifference for sorted array: \n");
    for(i = 0; i < k; i++)
    {
        printf("%d\n", E[i]);
    }
}
void UnionForNonSortedArray(int A[], int B[])
{
    int C[10], i, j = 0, k = 0, flag = 0;
    for(i = 0; i < 5; i++)
    {
        C[i] = A[i];
    }
    while(j < 5)
    {
        for(i = 0; i < 5; i++)
        {
            if(B[j] == A[i])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            C[5 + k++] = B[j];             
        }
        else
            flag = 0;
        j++;
    }
    printf("\nUnion for non sorted array: \n");
    for(i = 0; i <= 5+(k-1); i++)
    {
        printf("%d\n", C[i]);
    }
}
void UnionForSortedArray(int C[], int D[])
{
    int i = 0, j = 0, k = 0, E[10];
    while(i < 5 && j < 5)
    {
        if(C[i] > D[j])
        {
            if(C[i] == D[j])
            {
                E[k++] = C[i++];
                j++;
            }
            else
                E[k++] = D[j++];
        }
        else
        {
            if(C[i] == D[j])
            {
                E[k++] = C[i++];
                j++;
            }
            else
                E[k++] = C[i++];
        }
    }
    printf("\nUnion for sorted array: \n");
    for(i = 0; i < k; i++)
    {
        printf("%d\n", E[i]);
    }
}
int main()
{
    int A[5] = {3, 5, 16, 20, 4};
    int B[5] = {4, 10, 12, 22, 5};
    int C[5] = {3, 5, 16, 20, 24};
    int D[5] = {4, 10, 12, 20, 25};
    UnionForNonSortedArray(A, B);
    UnionForSortedArray(C, D);
    IntersectionForNonSortedArray(A, B);
    IntersectionForSortedArray(C, D);
    DifferenceForNonSortedArray(A, B);
    DifferenceForSortedArray(C, D);
}