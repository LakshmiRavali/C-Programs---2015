// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

// Trees.cpp : Defines the entry point for the console application.
//Find the weight of each node 

#include <stdafx.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Node 
{
	int value;
	Node * left;
	Node * right;
};

Node* createNode(int value)
{
	Node * node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void printNode(Node * root)
{
	printf("%d ", root->value);
}

void inorder(Node * root, void (*visit)(Node*))
{
	if (root == NULL) return;

	inorder(root->left, visit);
	visit(root);
	inorder(root->right, visit);
}


void preorder(Node * root, void (*visit)(Node*))
{
	if (root == NULL) return;

	visit(root);
	preorder(root->left, visit);
	preorder(root->right, visit);
}

void postorder(Node * root, void (*visit)(Node*))
{
	if (root == NULL) return;

	postorder(root->left, visit);
	postorder(root->right, visit);
	visit(root);
}

int weight(Node *root)
{
	int t1=0,t2=0;
	if(root==NULL)
		return 0;
	t1=weight(root->left);
	t2=(weight(root->right))+1;
	root->value=t1+t2;
}


int _tmain(int argc, _TCHAR* argv[])
{
	Node* n10 = createNode(10);
	Node* n20 = createNode(20);
	Node* n30 = createNode(30);
	Node* n40 = createNode(40);
	Node* n50 = createNode(50);

	n10->left = n20;
	n10->right = n40;
	n20-> right = n30;
	n30 -> right = n50;

	Node * root = n10;
	weight(root);
	printf("\n Inorder : ");
	inorder(root, printNode);
	printf("\n Preorder : ");
	preorder(root, printNode);
	_getch();
}


