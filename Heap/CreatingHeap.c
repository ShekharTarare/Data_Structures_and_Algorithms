#include<stdio.h>
#include<stdlib.h>
void InsertInHeap(int arr[], int n)
{
    int temp, i = n;
    temp = arr[n];
    while(i > 0 && temp > arr[(i-1)/2])
    {
        arr[i] = arr[(i-1)/2];
        i = (i-1)/2;
    }
    arr[i] = temp;
}
void Display(int arr[], int n)
{
    int i;
    printf("\nElements are: ");
    for(i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int A[] = {10, 20, 30, 25, 5, 40, 35};
    int i, n = 6;
    for(i = 1; i <= n; i++) //considering first element in place in heap. So, inserting from second location
    {
        InsertInHeap(A, i);
    }
    printf("\nAfter inserting: ");
    Display(A, n);
    return 0;
}
