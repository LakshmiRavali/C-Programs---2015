// Trees.cpp : Defines the entry point for the console application.
//In the given BST find the max number of childs

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


int count_childs(Node *root)
{
	int max;
	if(root==NULL)
		return -1;
	else if(root->left=='\0'&&root->right=='\0')
		return 0;
	else if(root->left!='\0'&&root->right!='\0')
		return 2;
	else if(root->left!='\0'&&root->right=='\0')
	{
		max=count_childs(root->left);
		if(max>1)
			return max;
		else
			return 1;
	}
	else if(root->right!='\0'&&root->left=='\0')
	{
		max=count_childs(root->right);
		if(max>1)
			return max;
		else
			return 1;
	}

}


int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	Node* n10 = createNode(10);
	Node* n20 = createNode(20);
	Node* n30 = createNode(30);
	Node* n40 = createNode(40);
	Node* n50 = createNode(50);

	n10->left = n20;
	n10->right = n40;
	n40-> right = n30;
	n30->right  = n50;
	n20 -> left = n50;

	Node * root = n10;
	n=count_childs(root);
	printf("the number of childs:%d",n);
	_getch();
}

