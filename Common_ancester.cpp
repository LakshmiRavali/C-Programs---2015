// Trees.cpp : Defines the entry point for the console application.
//

#include <stdafx.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#pragma warning(disable:4996)
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
int search(Node * root,int a)
{
	if(root==NULL)
		return -1;
	search(root->left,a);
	search(root->right,a);
	if(root->value==a)
		return 1;
}
void ancester(Node *root,int a,int b)
{
	if(root==NULL||(root->left==NULL&&root->right==NULL))
		return;
	/*else if(root->value>a&&root->value<b)
	{
		printf("%d",root->value);
		exit(0);
	}*/
	else if(root->value>a&&root->value>b)
	{
		ancester(root->left,a,b);
	}
	else if(root->value<a&&root->value<b)
		ancester(root->right,a,b);
	else
	{
		printf("%d",root->value);
		exit(0);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a,b;
	Node* n10 = createNode(50);
	Node* n20 = createNode(20);
	Node* n30 = createNode(30);
	Node* n40 = createNode(60);
	Node* n50 = createNode(40);

	n10->left = n20;
	n10->right = n40;
	n20-> right = n30;
	n30 -> right = n50;

	Node * root = n10;
	printf("enter a,b values");
	scanf("%d%d",&a,&b);
	if(search(root,a)!=-1&&search(root,b)!=-1)
		ancester(root,a,b);
	else 
		printf("no nodes");
	/*printf("\n Inorder : ");
	inorder(root, printNode);
	printf("\n Preorder : ");
	preorder(root, printNode);*/
	_getch();
}

