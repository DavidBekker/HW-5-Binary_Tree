#include<stdio.h>
#include"BST.h"
#include"reePrintLibrary.h"
#include <assert.h>
#include <stdlib.h>
#define CHECK_NULL(x) do\
{\
if (x == NULL)\
{\
	printf("Alocation fail\n");\
exit(1);\
}\
}while(0)

void initBST(BST* bst)
{
	bst->root= NULL;
}

TreeNode* createNode()
{

	TreeNode* tree = (TreeNode*)malloc(sizeof(TreeNode));
	CHECK_NULL(tree);
	tree->left = NULL;
	tree->right = NULL;
	return tree;
}
insert(TreeNode* root, TreeNode* newNode)
{
	
		
	if (newNode->element <= root->element)
		if (root->left == NULL)//?
		{
			root->left = newNode;
			return root->left;
		}
			
		else
			insert(root->left, newNode);

	if (newNode->element > root->element) //right subtree (>)
		if (root->right == NULL)
		{
			root->right = newNode;
			return root->right;
		}
		
			else
		
				insert(root->right, newNode);
	
}

void insertBST(BST* bst, int value)
{
	TreeNode* leev=createNode();
	leev->element = value;
	if (bst->root == NULL)
		bst->root = leev;
	else
	 insert(bst->root, leev); 
	
}

void printTreeInorder(BST* bst)
{
	printf("\n");
	if ((bst->root) != NULL)
		INprintTreeInorder(bst->root);
	else
		printf("Tree is Empty\n");
	printf("\n");
}

void INprintTreeInorder(TreeNode* ToPrint)
{
	if ((ToPrint) != NULL)
	{
		INprintTreeInorder(ToPrint->left);
		printf("%d ,", ToPrint->element);
		INprintTreeInorder(ToPrint->right);
	}
	
}

void destroyBST(BST* bst)
{
	if ((bst->root) != NULL)
		INdestroyBST(bst->root);
	else
		printf("Tree is Empty\n");
	
	initBST(bst);
	if ((bst->root) == NULL)
	printf("Tree is Empty\n");
}

void INdestroyBST(TreeNode* ToFree)
{

	if ((ToFree->left) != NULL)
		INdestroyBST(ToFree->left);

	else if ((ToFree->right) != NULL)
	{
		INdestroyBST(ToFree->right);
	}
	else
	{
		return;
	}
	free(ToFree);
	
}

int findIndexNFromLast(BST* bst, int N)
{
	if (bst->root == NULL)
		return 0;
	int highe = height(bst->root);
	TreeNode* temp= maxinTree(bst->root);
	int maxelementtree=temp->element;
	
	TreeNode* t = scantree(maxelementtree, bst,(highe-N));
	if (t == NULL)
		return 0;
	return t->element;
}
TreeNode* search(TreeNode* root, int k)
{
	int max=0;
	int count = 0;
	TreeNode* temp = root;
	while (temp != NULL)
	{
		if (temp->element == k)
			return(temp);

		if (k > temp->element)
			temp = temp->right;
		else
			temp = temp->left;

	}
	return NULL;//במידה ולא נמצא אף איבר
}

TreeNode* maxinTree(TreeNode* bst)
{
	TreeNode* temp=bst;
	if (bst->right != NULL)
	temp=maxinTree(bst->right);
	return(temp);
}
TreeNode* scantree(int Maxvalue, BST* bst,int index)
	{
	TreeNode* temp = NULL;
	if (index != 0||bst!=NULL||bst->root!=NULL)
	{
		if (bst->root->right!=NULL)
		if (bst->root->right->element < Maxvalue)
		{
			temp = scantree(Maxvalue, bst->root->right, --index);
			if(bst->root->left!=NULL)
			if (bst->root->left->element <= Maxvalue)
				temp = scantree(Maxvalue, bst->root->left, --index);
		}



	}
	return temp;

}
int height(TreeNode* node)
{
	if (node == NULL) return 0;
	return 1 + (maxs(height(node->left), height(node->right)));
}
int maxs(int a, int b)
{
	return (a >= b) ? a : b;
}
int sameHeightLeaves(BST* bst)
{
	if (bst->root == NULL)
		return 1;
	int l = height(bst->root->left);
	int r = height(bst->root->right);
	if (abs(l - r) <= 1 && sameHeightLeaves(bst->root->left) && sameHeightLeaves(bst->root->right))
		return 1;
	return 0;
}