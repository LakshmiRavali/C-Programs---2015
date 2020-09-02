#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
struct test
{
	int input[20], l1;
	char output[4];
}testDB[8] = {
		{ { 5, 2, 7, 1, 3, 6, 8 },  7,"yes" },
		{ { 1, 2, 3, 4 },  4,"no" },
		{ { 0 }, 0,"yes" },
		{ { 1, 2 }, 2,"no" },
		{ { 10, 8, 15, 5, 9, 13, 17, 4, 6 }, 9, "yes" },
		{ { 1, 2, 3, 5 }, 4, "no" },
		{ { 2, 1 }, 2, "yes" },
		{ { 2, 1, 3 }, 3, "yes" }
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

int compare(char *o1, char *o2)
{
	int i = 0;
	while (o1[i] != '\0' || o2[i] != '\0')
	{
		if (o1[i] != o2[i])
			return 1;
		i++;
	}
	return 0;
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

char *check_leftBStree(struct tree *root,int d)
{
	if (root == 0)
		return;
	else if (root->data < d)
	{
		check_leftBStree(root->left, d);
		check_leftBStree(root->right, d);
	}
	else
		return "no";
	return "yes";
}

char *check_rightBStree(struct tree *root, int d)
{
	if (root == 0)
		return;
	else if (root->data > d)
	{
		check_rightBStree(root->left, d);
		check_rightBStree(root->right, d);
	}
	else
		return "no";
	return "yes";
}

char *check_bs(struct tree *root)
{
	char *o1, *o2;
	struct tree *temp = (struct tree*)malloc(sizeof(struct tree));
	o1 = (char *)malloc(sizeof(char) * 4);
	o2 = (char *)malloc(sizeof(char) * 4);
	if (root!=0 && root->left != 0)
	{
		temp = root->left;
		o1 = check_leftBStree(temp, root->data);
	}
	else
		o1 = "yes";
	if (root!=0 && root->right != 0)
	{
		temp = root->right;
		o2 = check_rightBStree(temp, root->data);
	}
	else
		o2 = "yes";
	if (compare(o1, o2) == 0)
		return "yes";
	else
		return "no";
}


void testCases()
{
	int *input, j;
	int i, height;
	char *o;
	struct tree *root = (struct tree*)malloc(sizeof(struct tree));
	
	for (i = 0; i < 8; i++)
	{
		input = (int *)malloc(sizeof(int)*testDB[i].l1);
		o = (char *)malloc(sizeof(char) * 4);
		dynamic(testDB[i].input, input, testDB[i].l1);
		root = create_tree(input, 0, testDB[i].l1);
		o = check_bs(root);
		if (compare(o, testDB[i].output) == 0)
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