#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
struct test
{
	int input[20], output[20],l1,l2;
}testDB[8] = {
		{ { 1, 2, 3, 4, 5 ,6,7,8,9}, {1,2,3,4,5,6,7,8,9},9,9 },
		{ { 1, 2, 3, 4 }, {1,2,3,4},4,4 },
		{ {0}, {0},0,0 },
		{ { 1, 2 }, { 1, 2 },2,2 },
		{ { 22, 29, 12, 14 }, {22,29,12,14},4,4 },
		{ { 1 }, {1},1,1 },
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

struct tree *create_tree(int *input, struct tree *root,int low,int high)
{
	int mid;
	struct tree *temp=(struct tree*)malloc(sizeof(struct tree*));
	if (low > high)
	{
		root = '\0';
		return root;
	}
	else
	{
		mid = (low + high) / 2;
		temp->data = input[mid];
		temp->left = '\0';
		temp->right = '\0';
		root = temp;
		root->left = create_tree(input, root, low, mid - 1);
		root->right = create_tree(input, root, mid + 1, high);
		return root;
		
	}
}

int print_tree(struct tree *root,int *input,int i)
{
	if (root == NULL )
		return i;
	else
	{
		
		i=print_tree(root->left,input,i);
		input[i] = root->data;
		i=print_tree(root->right,input,i+1);
		
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
	int *input,j;
	int i;
	struct tree *root = (struct tree*)malloc(sizeof(struct tree));
	for (i = 0; i < 7; i++)
	{
		input = (int *)malloc(sizeof(int)*testDB[i].l1);
		dynamic(testDB[i].input, input, testDB[i].l1);
		root=create_tree(input, root,0,testDB[i].l1-1);
		print_tree(root,input,0);
		/*for (j = 0; input[j] != '\0'; j++)
			printf("%d ", input[j]);*/
		if (compare(input, testDB[i].output) == 0)
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