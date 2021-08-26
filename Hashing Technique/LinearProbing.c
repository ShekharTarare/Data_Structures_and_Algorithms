#include<stdio.h>
#define SIZE 10
int Hash(int key)
{
    return key % SIZE; //will return index
}
int Probe(int H[], int key)
{
    int index = Hash(key);
    int i = 0;
    while(H[(index + i) % SIZE] != 0) //run till next free space is found
        i++;
    return (index + i) % SIZE;
}
void Insert(int H[], int key)
{
    int index = Hash(key);
    if(H[index] != 0) //checking the index is free
        index = Probe(H, key); //if not free then call probe
    H[index] = key;
}
void Display(int HT[])
{
    int i;
    for(i = 0; i < SIZE; i++)
    {
        printf("%d ", HT[i]);
    }
    printf("\n");
}
int Search(int HT[], int key)
{
    int index = Hash(key);
    int i = 0;
    while(HT[(index + i) % SIZE] != key)
        i++;
    return (index + i) % SIZE;
}
int main()
{
    int HT[10] = {0};
    Display(HT);
    Insert(HT, 12);
    Display(HT);
    Insert(HT, 25);
    Display(HT);
    Insert(HT, 35);
    Display(HT);
    Insert(HT, 26);
    Display(HT);

    printf("\nKey %d found at %d", 35, Search(HT, 35));
    return 0;
}