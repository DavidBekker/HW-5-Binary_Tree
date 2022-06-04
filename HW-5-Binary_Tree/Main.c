#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"BST.h"
#include"reePrintLibrary.h"

void main()
{
	int ch = 0, key, element=0;
	char ans= 'n';
	BST NewTree;
	initBST(&NewTree);
	
	do
	{
		printf("\n1.Create");
		printf("\n2.Search");
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

			break;

		case 3:
			printTreeInorder(&NewTree);
			break;
		case 4:
			destroyBST(&NewTree);
			break;
		case 5:
			inorder(&NewTree.root);

		default: printf("Invalid Choice try again: \n");
			break;
		}

	} while (ch!=6);

		

	
}