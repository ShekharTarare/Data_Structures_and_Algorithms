#include<stdio.h>
#include<stdlib.h>
void InsertInHeap(int arr[], int n)
{
    int temp, i = n;
    temp = arr[n];
    while(i > 0 && temp > arr[i/2])
    {
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = temp;
}
void Display(int arr[], int n)
{
    int i;
    printf("\nElements are: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int arr[10] = {30, 20, 15, 5, 10, 12, 6}, inp, index;
    index = 7;
    printf("\nBefore inserting: ");
    Display(arr, index - 1);
    
    printf("\nEnter new element: ");
    scanf("%d", &inp);
    arr[index] = inp;
    InsertInHeap(arr, index);
    printf("\nAfter inserting: ");
    Display(arr, index);
    return 0;
}
