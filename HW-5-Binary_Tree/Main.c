#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"BST.h"
#include"reePrintLibrary.h"
#include <assert.h>
#include <stdlib.h>
void main()
{
	int ch = 0, key, element = 0, ValueOfTree = 0;
	int size, i;
	int* arr = NULL;
	char ans= 'n';
	BST NewTree;
	TreeNode* node;
	initBST(&NewTree);
	
	do
	{
		printf("\n1.Create");
		printf("\n2.Check if Tree in the same hieght ");
		printf("\n3.Print Tree");
		printf("\n4.Destroy Tree");
		printf("\n5.Find index from last");
		printf("\n6.exit");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			
				printf("Enter new element: \n");
				scanf("%d", &element);
				insertBST(&NewTree, element);

				//printf("Enter More element ? : (y/n): \n");
				//scanf("%c", &ans);
			
			break;
		case 2:
			if (sameHeightLeaves(&NewTree))
			printf("\na hieght balanced tree\n");
			else
				printf("\nNot a hieght balanced tree\n");
			break;
		case 3:
			print_ascii_tree(NewTree.root);
			printTreeInorder(&NewTree);
			break;
		case 4:
			destroyBST(&NewTree);
			break;
		case 5:
			
			key = findIndexNFromLast(&NewTree, 3);// need update
			break;
		default: printf("Invalid Choice try again: \n");
			break;
		}

	} while (ch!=6);

		

	
}