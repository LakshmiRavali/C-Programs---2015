// project.cpp : Defines the entry point for the console application.
//Find wether the given tree is BST or not

#include "stdafx.h"
#include "stdlib.h"
#include "conio.h"
struct Node 
{
	int value,max;
	Node * left;
	Node * right;
}id;

Node* createNode(int value)
{
	Node * node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	node->max=1;
	return node;
}



void find(Node *root)
{
	printf("Not a bst");
}


int postorder(Node * root, void (*visit)(Node*))
{
	if (root == NULL) return 0;
	if(root->left!='\0')
		if(root->value>root->left->value)
			postorder(root->left,visit);
		else
		{
			visit(root);
			return -1;
			exit(0);
			
		}
	else if(root->right!='\0')
	{
		if(root->value<root->right->value)
			postorder(root->right,visit);
		else
		{
			visit(root);
			return -1;
			exit(0);
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	Node* n10 = createNode(50);
	Node* n20 = createNode(20);
	Node* n30 = createNode(30);
	Node* n40 = createNode(60);
	Node* n50 = createNode(40);
	Node* n60= createNode(70);

	n10->left = n20;
	n10->right = n40;
	n20-> right = n30;
	n30 -> right = n50;
	n40->right=n60;

	Node * root = n10;
	i=postorder(root,find);
	if(i!=-1)
		printf("it is a BST");
	_getch();
	return 0;
}

