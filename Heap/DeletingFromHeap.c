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
int Delete(int A[], int n)
{
    int i, j, x, temp, val;
    val = A[0]; //element to be deleted
    x = A[n]; //taking last element to temp var
    A[0] = A[n]; //last elementis copied to first
    A[n] = val; //copied deleted value to last location
    i = 0; //first element
    j = i * 2; //left child

    while(j < n) //till less than the element less than the last element
    {
        if(A[j + 1] > A[j])
            j = j + 1;
        if(A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
            break;
    }
    return val;
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

    printf("\nAfter deleting %d: ", Delete(A, n));
    Display(A, n);
    return 0;
}
