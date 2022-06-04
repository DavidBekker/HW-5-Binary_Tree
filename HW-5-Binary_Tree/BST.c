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
	TreeNode* temp = search(bst->root, N);
	if(temp==NULL)
	return 0;
	
}
void inorder(TreeNode* root)
{
	if (root != NULL)
	{
		inorder(root->right);
	}
}
TreeNode* Maxvalue(TreeNode* node)
{
	TreeNode* current = node;
	while (current && current->right != NULL)
		current = current->right;
	return current;
}
TreeNode* search(TreeNode* root, int k)
{
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

