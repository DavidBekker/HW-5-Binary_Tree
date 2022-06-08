#define _CRT_SECURE_NO_WARNINGS
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
	bst->root = NULL;
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
	TreeNode* leev = createNode();
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
	int size=0, max=0;
	int i = 0;
	int* arr = NULL;
	if (bst->root == NULL)
		return 0;
	size = sizetree(bst->root);
	arr = calloc(size, sizeof(int));
	AddToArry(bst->root, arr, &i);


	return arr[size - N];

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


int AddToArry(TreeNode* node, int arr[], int *i)
{
	if (node == NULL)
		return i;

	arr[*i] = node->element;
	++* i;
	AddToArry(node->left, arr, i);
	AddToArry(node->right, arr, i);
}

int sizetree(TreeNode* node)
{
	int x= 1;
	if (node == NULL)
		return 0;

	else
	{
		x += sizetree(node->left);
		x += sizetree(node->right);
		return x;
	}
}