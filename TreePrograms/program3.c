#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
struct test
{
	int input[20], h,l1;
}testDB[8] = {
		{ { 1, 2, 3, 4, 5, 6, 7, 8, 9 },  3, 9 },
		{ { 1, 2, 3, 4 },  2, 4 },
		{ { 0 },  0, 0 },
		{ { 1, 2 },  1, 2 },
		{ {1},0,1 },
		{ {3,1},1,2 }
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

void create_root(int *input, struct tree *root)
{
	root->data = input[0];
	root->left = '\0';
	root->right = '\0';
}


struct tree* create_tree(int *input, int n ,int high)
{
	struct tree *root = NULL;
	if (n < high)
	{
		root = (struct tree*)malloc(sizeof(struct tree));
		root->left = create_tree(input, 2 * n + 1,high);
		root->data = input[n];
		root->right = create_tree(input, 2 * n + 2,high);
	}
	return root;
}

int calculate_height(struct tree *root)
{
	int height = 0;
	while (root!=0 && root->left != 0)
	{
		root = root->left;
		height++;
	}
	return height;
}

void testCases()
{
	int *input, j;
	int i,height;
	struct tree *root = (struct tree*)malloc(sizeof(struct tree));
	for (i = 0; i < 7; i++)
	{
		input = (int *)malloc(sizeof(int)*testDB[i].l1);
		dynamic(testDB[i].input, input, testDB[i].l1);
		root = create_tree(input, 0,testDB[i].l1);
		height = calculate_height(root);
		if (height==testDB[i].h)
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