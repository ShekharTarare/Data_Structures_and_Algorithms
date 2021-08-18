#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
    struct TreeNode *lchild;
    int data;
    struct TreeNode *rchild;
}*root = NULL;
void Insert(int key)
{
    struct TreeNode *p, *t, *r;
    p = root;
    if(p == NULL)
    {
        t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        t -> data = key;
        t -> lchild = t -> rchild = NULL;
        root = t;
        return; //stop after inserting first node
    }
    //Searching the key if it is available already
    while(p != NULL)
    {
        r = p;
        if(key == p -> data)
            return;
        else if(key < p -> data)
            p = p -> lchild;
        else
            p = p -> rchild;
    }
    //if key not available then create new node with the data as key
    t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    t -> data = key;
    t -> lchild = t -> rchild = NULL;
    //insert to left if key is lesser 
    if(r -> data > t -> data)
        r -> lchild = t;
    else    
        r -> rchild = t; //Insert to right
}
void Inorder(struct TreeNode *p)
{
    if(p)
    {
        Inorder(p -> lchild);
        printf("%d ", p -> data);
        Inorder(p -> rchild);
    }
}
struct TreeNode *Search(int key)
{
    struct TreeNode *p;
    p = root;
    while(p != NULL)
    {
        if(key == p -> data)
            return p;
        else if(key < p -> data)
            p = p -> lchild;
        else
            p = p -> rchild;
    }
    return NULL;
}
struct TreeNode *RecursiveInsert(struct TreeNode *p, int key)
{
    struct TreeNode *t = NULL;
    if(p == NULL)
    {
        t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        t -> data = key;
        t -> lchild = t -> rchild = NULL;
        return t;
    }
    if(key < p -> data)
        p -> lchild = RecursiveInsert(p -> lchild, key);
    else if(key > p -> data)
        p -> rchild = RecursiveInsert(p -> rchild, key);
    return p;
}
//We can select predecessors directly also, but here we are finding the heigt
//first and then replacing the element which is present in the side whose height is lesser.
int Height(struct TreeNode *p)
{
    int x, y;
    if(p == NULL)
        return 0;
    x = Height(p -> lchild);
    y = Height(p -> rchild);
    return x > y ? x + 1 : y + 1;
}
struct TreeNode *InPre(struct TreeNode *p)
{
    while(p && p -> rchild != NULL)
        p = p -> rchild;
    return p;
}
struct TreeNode *InSucc(struct TreeNode *p)
{
    while(p && p -> lchild != NULL)
        p = p -> lchild;
    return p;
}
struct TreeNode *Delete(struct TreeNode *p, int key)
{
    struct TreeNode *q;
    if(p == NULL)
        return NULL;
    if(p -> lchild == NULL && p -> rchild == NULL)
    {
        if(p == root)
            root = NULL;
        free(p);
        return NULL; 
    }
 
    if(key < p -> data)
        p -> lchild = Delete(p -> lchild, key);
    else if(key > p -> data)
        p -> rchild = Delete(p -> rchild, key);
    else
    {
        //We can select predecessors directly also, but here we are finding the heigt
        //first and then replacing the element which is present in the side whose height is greater.
        if(Height(p -> lchild) > Height(p -> rchild))
        {
            q = InPre(p -> lchild);
            p -> data = q -> data;
            p -> lchild = Delete(p -> lchild, q -> data);
        }
        else
        {
            q = InSucc(p -> rchild);
            p -> data = q -> data;
            p -> rchild = Delete(p -> rchild, q -> data);
        }
    }
    return p;
}
int main()
{
    struct TreeNode *t;
    root = RecursiveInsert(root, 10); //passing first time so that to store address of first node in root
    Insert(10);
    Insert(5);
    RecursiveInsert(root, 20);
    Insert(8);
    RecursiveInsert(root, 30);

    printf("\nBefore deletion: ");
    Inorder(root);
    printf("\nAfter deletion: ");
    Delete(root, 10);
    Inorder(root);

    t = Search(20);
    if(t != NULL)
        printf("\nElement %d is found\n", t -> data);
    else
        printf("\nElement %d is not found\n", t -> data);
    return 0;
}