#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"BST.h"
#include"reePrintLibrary.h"

void main()
{
	int v;
	BST NewTree;
	initBST(&NewTree);

	while (1)
	{
		printf("\nEnter a Value for the tree \n");
		scanf("%d", &v);
		switch (v)
		{
		case 0:
			printTreeInorder(&NewTree);
			break;
		case 1:
			destroyBST(&NewTree);
			break;
		default: insertBST(&NewTree, v);
			break;
		}

		
	}

	
}