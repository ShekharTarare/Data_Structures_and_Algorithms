//Chains.h
 
//Start Here
#ifndef Chains_h
#define Chains_h
 
#include <stdlib.h>
#include <stdio.h>
 
struct Node
{
    int data;
    struct Node *next;
};
 
typedef struct Node *NODE;
NODE *HT; //Declaring Hash Table as Global Variable
 
void sortedInsert(int index, int key)
{
    NODE q, temp, p;
    q = p = NULL;
    temp = (NODE)malloc(sizeof(struct Node));
    temp->data = key;
    temp->next = NULL;
    if (HT[index] == NULL)
    {
        HT[index] = temp;
    }
    else
    {
        p = HT[index];
        while (p && key > p->data)
        {
            q = p;
            p = p->next;
        }
        if (p == NULL) //This means it is the largest number in the list
        {
            q->next = temp;
        }
 
        else
        {
            //Inserting Data at Head Node
            if (p == HT[index])
            {
                temp->next = p;
                HT[index] = temp;
            }
 
            else //Inserting data between two Nodes
            {
                q->next = temp;
                temp->next = p;
            }
        }
    }
}
 
 
#endif
 
//Chains.h End Here