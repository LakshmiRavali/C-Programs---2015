//Given a binary tree,print the nodes that are apper from right side.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)


struct test
{
	int input[20], output[20], l1, l2;
}testDB[8] = {
		{ { 1, 2, 3, 4, 5, 6, 7,8 }, { 1, 3,7,8 }, 8, 4 },
		{ { 1, 2, 3, 4 }, { 1, 3, 4 }, 4, 3 },
		{ { 0 }, { 0 }, 0, 0 },
		{ { 1, 2 }, { 1, 2 }, 2, 2 },
		{ { 1 }, { 1 }, 1, 1 },
		{ { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, {1,3,7,9},9,4 }
};
struct tree
{
	struct tree *left;
	struct tree *right;
	int data;
};
void dynamic(int *a, int *b, int n)
{
	int i = 0;
	while (i < n)
	{
		b[i] = a[i];
		i++;
	}
	b[i] = '\0';
}

struct tree* create_tree(int *input, int n, int high)
{
	struct tree *root = NULL;
	if (n < high)
	{
		root = (struct tree*)malloc(sizeof(struct tree));
		root->left = create_tree(input, 2 * n + 1, high);
		root->data = input[n];
		root->right = create_tree(input, 2 * n + 2, high);
	}
	return root;
}


int right_depth(struct tree *root,int *input,int p)
{
	if (root == NULL)
	{
		//q = p;
		return p;
	}
	else
	{
		//printf("%d ", root->data);
		input[p] = root->data;
		p = right_depth(root->right, input, p + 1);
	}
	return p;
}


int print_tree(struct tree *root, int *input, int i,int p,int q)
{
	if (root == NULL && root==NULL)
	{
		return ;
	}
	else
	{
		
		print_tree(root->left, input, i + 1, p + 1, q);

		 print_tree(root->right, input, i,p+1,q);
		
		 if (p >= q)
		 {
			 input[p] = root->data;
			// printf(" %d ", root->data);
			 input[p + 1] = '\0';
		 }
	}
}

int compare(int *input, int *output)
{
	int i;
	for (i = 0; input[i] != '\0' || output[i] != '\0'; i++)
		if (input[i] != output[i])
			return 1;
	return 0;
}

void testCases()
{
	int *input, j,p=0,*output;
	int i;
	struct tree *root = (struct tree*)malloc(sizeof(struct tree));
	for (i = 0; i < 7; i++)
	{
		input = (int *)calloc(sizeof(int),testDB[i].l1);
		output = (int *)calloc(sizeof(int), testDB[i].l2);
		dynamic(testDB[i].input, input, testDB[i].l1);
		root = create_tree(input, 0, testDB[i].l1);
		p = right_depth(root,output, 0);
		output[p] = '\0';
		print_tree(root, output, 0,0,p);
		if (compare(output, testDB[i].output) == 0)
			printf("passed\n");
		else
			printf("failed\n");
	}
}
void main()
{
	testCases();
	_getch();
}