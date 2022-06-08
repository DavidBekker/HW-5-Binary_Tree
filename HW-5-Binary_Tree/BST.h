#ifndef _BST_ADT_H
#define _BST_ADT_H

typedef struct TreeNode TreeNode;

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int element;
};

typedef struct BST
{
    TreeNode* root;
}BST;

//Q1: init new Tree: 
void initBST(BST* bst);//מאפסת את העץ

//Q2 insert new value to tree
insert(TreeNode* root, TreeNode* newNode);
TreeNode* createNode();//מוסיפה איבר חדש לעץ
void insertBST(BST* bst, int value);

//Q3 Print Tree:
void printTreeInorder(BST* bst);
void INprintTreeInorder(TreeNode* ToPrint);

// Q4 Destroy Tree:
void destroyBST(BST* bst);
void INdestroyBST(TreeNode* ToFree);

//Q5 finde index from last(max):
//TreeNode* maxinTree(TreeNode* bst);//מחזירה את האלמנט הגדול ביות בעץ
int findIndexNFromLast(BST* bst, int N);
//Help functions
int AddToArry(TreeNode* node, int arr[], int i);//מעבירה את כל תוכן העץ לתוך מערך
int sizetree(TreeNode* node);//מחזירה את גודל העץ
int compare(const void* a, const void* b);

//Q6 if Same high level:
int sameHeightLeaves(BST* bst);
int height(TreeNode* node);//מחזיר את גובה העץ
TreeNode* search(TreeNode* root, int k);//מחזיר את האיבר שאיתו נסרק העץ
void inorderr(TreeNode* root);

#endif // !_BST_ADT_H