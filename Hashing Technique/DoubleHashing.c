#include<stdio.h>
#define SIZE 10
#define R 7 //prime number closer to 10
int Hash(int key)
{
    return key % SIZE; //will return index
}
int Hash2(int key)
{
    return R - (key % R);
}
int Probe(int H[], int key)
{
    int index = Hash(key);
    int i = 0;
    while(H[(index + i * Hash2(key)) % SIZE] != 0) //run till next free space is found
        i++;
    return (index + i * Hash2(key)) % SIZE;
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
    while(HT[(index + i * Hash2(key)) % SIZE] != key)
        i++;
    return (index + i * Hash2(key)) % SIZE;
}
int main()
{
    int HT[10] = {0};
    Display(HT);
    Insert(HT, 5);
    Display(HT);
    Insert(HT, 25);
    Display(HT);
    Insert(HT, 15);
    Display(HT);
    Insert(HT, 35);
    Display(HT);
    Insert(HT, 95);
    Display(HT);

    printf("\nKey %d found at %d", 35, Search(HT, 35));
    return 0;
}