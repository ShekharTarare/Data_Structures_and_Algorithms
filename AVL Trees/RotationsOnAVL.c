#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
    struct TreeNode *lchild;
    struct TreeNode *rchild;
    int data;
    //maintaining height to calculate the balance factor for each node
    int height;
}*root = NULL;
//Taking the height of the subtree whose height is greater, this may be left or right subtree
int NodeHeight(struct TreeNode *p)
{
    int hl, hr;
    //height of left subtree and height of right subtree
    hl = p && p -> lchild ? p -> lchild -> height : 0;
    hr = p && p -> rchild ? p -> rchild -> height : 0;
    //We are adding 1 because, suppose we have height on left side is 3 and height on right side is 1
    //If we apply above logic we will get height as 2 that's why adding 1. And as per the logic we are 
    //setting height as 1 after adding first node. So if it is having one root node and one extra node
    //then height will become 2 after adding one
    return hl > hr ? hl + 1 : hr + 1;
}
int BalanceFactor(struct TreeNode *p)
{
    int hl, hr;
    hl = p && p -> lchild ? p -> lchild -> height : 0;
    hr = p && p -> rchild ? p -> rchild -> height : 0;
    return hl - hr;
}
struct TreeNode *LLRotation(struct TreeNode *p)
{
    //p is pointing to root node
    //pl is pointing to left child of root node
    //plr is pointing to right child of pl
    //We are taking plr to transfer that node to the right side after rotations
    struct TreeNode *pl = p -> lchild;
    struct TreeNode *plr = pl -> rchild;

    pl -> rchild = p;
    p -> lchild = plr;
    p -> height = NodeHeight(p);
    pl -> height = NodeHeight(pl);
    //plr height will not change as it is pointing downwards only

    //If rotation is performed on root then it should be change
    if(root == p)
        root = pl;
    
    //return new root
    return pl;
}
struct TreeNode *RRRotation(struct TreeNode *p)
{
    struct TreeNode *pr = p -> rchild;
    struct TreeNode *prl = pr -> lchild;
    
    pr -> lchild = p;
    p -> rchild = prl;

    p -> height = NodeHeight(p);
    pr -> height = NodeHeight(pr);

    if(root == p)
        root = pr;
    return pr;
}
struct TreeNode *LRRotation(struct TreeNode *p)
{
    struct TreeNode *pl = p -> lchild;
    struct TreeNode *plr = pl -> rchild;

    pl -> rchild = plr -> lchild;
    p -> lchild = plr -> rchild;

    plr -> lchild = pl;
    plr -> rchild = p;

    pl -> height = NodeHeight(pl);
    p -> height = NodeHeight(p);
    plr -> height = NodeHeight(plr);

    if(root == p)
        root = plr;

    return plr;
}
struct TreeNode *RLRotation(struct TreeNode *p)
{
    struct TreeNode *pr = p -> rchild;
    struct TreeNode *prl = pr -> lchild;

    p -> rchild = prl -> lchild;
    pr -> lchild = prl -> rchild;

    prl -> rchild = pr;
    prl -> lchild = p;

    p -> height = NodeHeight(p);
    pr -> height = NodeHeight(pr);
    prl -> height = NodeHeight(prl);

    if(root == p)
        root = prl;

    return prl;
}
struct TreeNode *RecursiveInsert(struct TreeNode *p, int key)
{
    struct TreeNode *t = NULL;
    if(p == NULL)
    {
        t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        t -> data = key;
        t -> height = 1; //we can take 0 as well
        t -> lchild = t -> rchild = NULL;
        return t;
    }
    if(key < p -> data)
        p -> lchild = RecursiveInsert(p -> lchild, key);
    else if(key > p -> data)
        p -> rchild = RecursiveInsert(p -> rchild, key);
    
    //Updating the height after inserting the data
    p -> height = NodeHeight(p);

    //We should know bf of each node to perform rotations
    if(BalanceFactor(p) == 2 && BalanceFactor(p -> lchild) == 1)
        LLRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p -> lchild) == -1)
        LRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p -> rchild) == -1)
        RRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p -> rchild) == 1)
        RLRotation(p);
    return p;
}
void Display(struct TreeNode *p)
{
    if(p)
    {
        Display(p -> lchild);
        printf("%d ", p -> data);
        Display(p -> rchild);
    }
}
int main()
{
    root = RecursiveInsert(root, 15);
    RecursiveInsert(root, 13);
    RecursiveInsert(root, 14);

    Display(root);
    return 0;
}