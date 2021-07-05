#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Array 
{
    int* A;
    int size;
    int length; 
};
void Display(struct Array arr)
{
    int i;
    printf("The array values are: \n");
    for(i = 0; i < arr.length; i++)
    {
        printf("%d\n", arr.A[i]);
    }
}
void Append(struct Array* arr, int value)
{
    if(arr->length < arr->size)
    {
        arr->A[arr->length] = value;
        arr->length++;
        printf("\n%d appended successfully!", value);
    }
    else
    {
        printf("\nArray is full!");
    }
}
void Insert(struct Array* arr, int index, int value)
{
    if(arr->length == arr->size)
    {
        printf("\nArray is Full, please delete some values to enter new values!");
    }
    else
    {
        if(index > arr->size)
        {
            printf("\nIndex cannot be larger then the size of an array!");
        }
        else
        {
            if(index < 0)
            {
                printf("\nInvalid index!");
            }
            else
            {
                for(int i = arr->length; i >= index; i--)
                {
                    arr->A[i] = arr->A[i-1];
                }
                arr->A[index-1] = value;
                arr->length++;
                printf("\nThe value %d has been inserted at index %d!", value, index);
            }            
        }
    }
}
void Delete(struct Array* arr, int index)
{
    if(arr->length == 0)
    {
        printf("\nArray is empty!");
    }
    else
    {
        if(index < 0)
        {
            printf("\nInvalid index!");
        }
        else
        {
            if(index >= arr->size)
            {
                printf("\nIndex can not be larger than the size of an array!");
            }
            else
            {
                for(int i = index; i < arr->length; i++)
                {
                    arr->A[i] = arr->A[i + 1];
                }
                arr->length--;
                printf("\nValue at index %d has been deleted!", index);
            }
        }
    }
}
void Search(struct Array arr, int key)
{
    void LinearSearch(struct Array arr, int value);
    void BinarySearch(struct Array arr, int value);

    int choice;
    printf("\nChoose any one operation from below: ");
    printf("\n1. Linear Search \n2. Binary Search \n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1: LinearSearch(arr, key);
                break;
            
        case 2: BinarySearch(arr, key);
                break;

        default: printf("\nInvalid option!");        
    }
}
void LinearSearch(struct Array arr, int key)
{
    int index;
    for(int i = 0; i <= arr.length; i++)
    {
        if(arr.A[i] == key)
        {
            index = i;
            break;
        }
        else
        {
            index = -1;
        }
    }
    index != -1 ? printf("\nThe key %d found at index %d!", key, index): printf("\nKey not found!");
}
void BinarySearch(struct Array arr, int key)
{
    int mid, first = 0, last = arr.length - 1, index = -1;

    while (first <= last)
    {                
        mid = (first + last) / 2;
        if(arr.A[mid] == key)
        {
            index = mid;
            break;
        }
        else if(key > arr.A[mid])
        {
            first = mid + 1;
        }
        else 
        {
            last = mid - 1;
        }
    }        
    index != -1 ? printf("\nThe key %d found at index %d!", key, index) : printf("\nKey not found!");
}
void Get(struct Array arr, int index)
{
    if(index > arr.length)
    {
        printf("\nIndex cannot be greater than the size of an array!");
    }
    else
    {
        printf("\nThe %d is stored at %d", arr.A[index], index);
    }
}
void Set(struct Array* arr, int index, int value)
{
    if(index > arr->length)
    {
        printf("\nIndex cannot be greater than the size of an array!");
    }
    else
    {
        arr->A[index] = value;
        printf("\nThe %d value is set to the index %d", value, index);
    }
}
void Max(struct Array arr)
{
    int max = arr.A[0];
    for(int i = 1; i < arr.length; i++)
    {
        if(max < arr.A[i])
        {
            max = arr.A[i];
        }
    }
    printf("\nThe max value is %d", max);
}
void Min(struct Array arr)
{
    int min = arr.A[0];
    for(int i = 1; i < arr.length; i++)
    {
        if(min > arr.A[i])
        {
            min = arr.A[i];
        }
    }
    printf("\nThe min value is %d", min);
}
void Swap(int* first, int * second)
{
    int temp;
    temp = *first;
    *first = *second;
    *second = temp;
}
void Reverse(struct Array* arr)
{
    int i, j;
    for(i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        Swap(&arr->A[i], &arr->A[j]);
    }
}
int Sum(struct Array arr)
{
    int sum = 0, i;
    for(i = 0; i < arr.length; i++)
    {
        sum = sum + arr.A[i];
    }
    return sum;
}
void Average(struct Array arr)
{
    printf("\nThe average is %f", (float)Sum(arr) / 2);
}
void Shift(struct Array* arr)
{
    int choice, i;
    printf("\nChoose the operation from below: ");
    printf("\n1. Left shift \n2. Right shift\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1: for(i = 0; i < arr->length - 1; i++)
                {
                    arr->A[i] = arr->A[i + 1];
                }
                arr->A[arr->length - 1] = 0;
                break;

        case 2: for(i = arr->length - 1; i > 0 ; i--)
                {
                    arr->A[i] = arr->A[i - 1];
                }
                arr->A[0] = 0;
                break;

        default: printf("\nInvalid  option");
    }
}
void Rotate(struct Array* arr)
{
    int i, temp;
    temp = arr->A[0];
    for(i = 0; i < arr->length-1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }    
    arr->A[arr->length - 1] = temp;
}
void InsertInSortedAray(struct Array* arrPointer, struct Array arr)
{
    int CheckingArrayIsSorted(struct Array arr);
    int i = arr.length - 1, inp, index = -1;
    if(CheckingArrayIsSorted(arr))
        printf("\nArray is not sorted!");
    else
    {
        if(arrPointer->length == arrPointer->size)
        {
            printf("\nArray is full!\n");
        }
        else
        {
            printf("\nEnter the value to be inserted: ");
            scanf("%d", &inp);
            while(arrPointer->A[i] > inp && i >= 0)
            {
                arrPointer->A[i+1] = arrPointer->A[i];
                i--;
            }
            arrPointer->A[i+1] = inp;
            arrPointer->length++;
        }
    }    
}
int CheckingArrayIsSorted(struct Array arr)
{
    for(int i = 0; i < arr.length - 1; i++)
    {
        if(arr.A[i] > arr.A[i+1])
        {
            return 1;
        }
    }
    return 0;
}
void ArrangingNegativeOnLeft(struct Array* arr)
{
    int i, j;
    for(i = 0, j = 0; i < arr->length; i++)
    {
        if(arr->A[i] < 0)
        {
            Swap(&arr->A[i], &arr->A[j]); //swap negative with negative or negative with positive
            j++; //increment if negative number
        }
    }
}
int main()
{
    int n, i, choice, inp, index;
    struct Array arr;

    printf("\nEnter the size of an array: ");
    scanf("%d", &arr.size);
    arr.length = 0;
    
    arr.A = (int *)malloc(arr.size*sizeof(int));

    printf("\nEnter the number of values you are going to enter: ");
    scanf("%d", &n);
    arr.length = n;

    printf("\nEnter the arrays: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr.A[i]);
    }

    while(choice != 13)
    {
        printf("\n\nPlease select the operation from the below menu: ");
        printf("\n1. Display \n2. Append \n3. Insert \n4. Delete \n5. Search \n6. Get \n7. Set \n8. Max ");
        printf("\n9. Min \n10. Reverse \n11. Sum \n12. Average \n13. Shift \n14. Rotate ");
        printf("\n15. Inserting in a sorted array \n16. Checking if an array is sorted \n17. Arranging negative on left side ");
        printf("\n18. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: Display(arr);
                    break;
            
            case 2: printf("\nEnter the value to append: ");
                    scanf("%d", &inp);
                    Append(&arr, inp);
                    break;

            case 3: printf("\nEnter the index: ");
                    scanf("%d", &index);
                    printf("\nEnter the value: ");
                    scanf("%d", &inp);
                    Insert(&arr, index, inp);
                    break;
            
            case 4: printf("\nEnter the index: ");
                    scanf("%d", &index);
                    Delete(&arr, index);
                    break;

            case 5: printf("\nEnter the value to search: ");
                    scanf("%d", &inp);
                    Search(arr, inp);
                    break;
            
            case 6: printf("\nEnter the index to get the value: ");
                    scanf("%d", &inp);
                    Get(arr, inp);
                    break;
                
            case 7: printf("\nEnter the index to set the value: ");
                    scanf("%d", &index);
                    printf("\nEnter the value to set: ");
                    scanf("%d", &inp);
                    Set(&arr, index, inp);
                    break;

            case 8: Max(arr);
                    break;

            case 9: Min(arr);
                    break;

            case 10: Reverse(&arr);
                     Display(arr);
                     break;

            case 11: printf("\nThe sum is %d", Sum(arr));
                     break;

            case 12: Average(arr);
                     break;

            case 13: Shift(&arr);
                     Display(arr);
                     break;

            case 14: Rotate(&arr);
                     Display(arr);
                     break;

            case 15: InsertInSortedAray(&arr, arr);
                     Display(arr);
                     break;

            case 16: inp = CheckingArrayIsSorted(arr);
                     if(inp == 1)
                        printf("\nArray is not sorted!");
                     else
                        printf("\nArray is sorted!");
                     break;

            case 17: ArrangingNegativeOnLeft(&arr);
                     Display(arr);
                     break;

            case 18: printf("Thanks!"); 
                     exit(1);

            default: printf("\nInvalid option");
        }   
    } 
    free(arr.A);
    getch();
    return 0;
}