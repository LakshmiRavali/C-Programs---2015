#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};

void create_root(int *input, struct tree *root)
{
	root->data = input[0];
	root->left = '\0';
	root->right = '\0';
}
void insert_elements(int value, struct tree *root)
{
	struct tree *temp = (struct tree*)malloc(sizeof(struct tree));
	temp->data = value;
	temp->left = '\0';
	temp->right = '\0';
	if (root->data > temp->data)
	{
		if (root->left == '\0')
			root->left = temp;
		else
		{
			root = root->left;
			insert_elements(value, root);
		}
	}
	else if (root->data < temp->data)
	{
		if (root->right == '\0')
			root->right = temp;
		else
		{
			root = root->right;
			insert_elements(value, root);
		}
	}
}

void create_tree(int *input, struct tree *root)
{
	int i = 1;
	create_root(input, root);
	while (input[i] != 0)
	{
		insert_elements(input[i], root);
		i++;
	}
}

void print_inorder_tree(struct tree *root)
{
	if (root == NULL)
		return;
	else
	{
		print_inorder_tree(root->left);
		printf("%d ", root->data);
		print_inorder_tree(root->right);
	}
}

void print_preorder_tree(struct tree *root)
{
	if (root == NULL)
		return;
	else
	{
		printf("%d ", root->data);
		print_preorder_tree(root->left);
		print_preorder_tree(root->right);
	}
}

void print_postorder_tree(struct tree *root)
{
	if (root == NULL)
		return;
	else
	{
		print_postorder_tree(root->left);
		print_postorder_tree(root->right);
		printf("%d ", root->data);
	}
}

void main()
{
	int *input,n,i;
	struct tree *root = (struct tree *)malloc(sizeof(struct tree));
	printf("enter number elements in the tree");
	scanf("%d", &n);
	input = (int *)malloc(sizeof(int)*n);
	printf("enter elements:");
	for (i = 0; i < n; i++)
		scanf("%d", &input[i]);
	input[i] = 0;
	if (input[0] != 0)
	{
		create_tree(input, root);
		printf("\ninorder:");
		print_inorder_tree(root);
		printf("\npreorder:");
		print_preorder_tree(root);
		printf("\npostorder:");
		print_postorder_tree(root);
	}
	else
		printf("\nerror");
	_getch();
}