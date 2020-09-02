#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
struct node
{
	int data;
	struct node *next;
};
struct test
{
	char input[20], output[20];
	int l1,l2;
}testDB[9] = { { "1,2,3,4,5,6,7", "2,4,6", 13,5},
{ "2,3,4,6,7", "2,4,6", 9, 5 },
{ "12,14,16", "12,14,16", 8, 8 },
{ "1,3,8", "8", 5, 1 },
{ "1,3,5,7", "",7,0 },
{ "1,2,3,3,4,5", "2,4", 11, 3 },
{ "", "", 0, 0 },
{ "-1,2,-3,4,-5", "2,4",12,3 }
};
void testCases(struct node *, struct node *, struct node *);
struct node* string_to_linkedlist(char *, struct node *);
struct node* create(char *, struct node *);
struct node* insert(char *, struct node *);
int compare(struct node*, struct node *);
int calculation(char *, int);
struct node* odd_remove(char *, struct node *, int, int);
int calculation(char *input, int i)
{
	int j = 0, p = 1, value = 0;
	p = 1;
	value = 0;
	while (i >= 0 && input[i] != ',')
	{
		if (input[i] != '-')
		{
			value = value + (input[i] - 48)*p;
			p = p * 10;
		}
		else
			value = (-value);
		i--;
	}
	return value;
}
int compare(struct node* input, struct node* output)
{
	while (input != 0 || output != 0)
	{
		if (input->data != output->data)
			return 1;
		input = input->next;
		output = output->next;
	}
	return 0;
}
struct node* create(char *input, struct node *root)
{
	int value, i = 0;
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	while (input[i] != ','&&input[i] != '\0')
		i++;
	i--;
	value = calculation(input, i);
	temp->next = 0;
	temp->data = value;
	root = temp;
	return root;
}
struct node* insert(char *input, struct node *root)
{
	int value, i = 0, j;
	struct node *curr = (struct node *)malloc(sizeof(struct node));
	curr = root;
	while (input[i] != ','&&input[i] != '\0')
		i++;
	i++;
	while (input[i] != ','&&input[i] != '\0'&&input[i-1]!='\0')
		i++;
	i--;
	while (input[i] != '\0'&&input[i - 2] != '\0'&&input[i - 1] != '\0')
	{
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		while (input[i] != ','&&input[i] != '\0')
			i++;
		j = i + 1;
		i--;
		value = calculation(input, i);
		temp->next = 0;
		temp->data = value;
		curr->next = temp;
		curr = temp;
		i = j;
	}

	curr->next = 0;
	return root;
}
struct node* string_to_linkedlist(char *input, struct node *root)
{
	if (input[0] == 0)
		return 0;
	else
	{
		root = create(input, root);
		root = insert(input, root);
	}
	return root;
}
struct node* odd_remove(char *input, struct node *root)
{
	int i = 0;
	struct node *curr = (struct node *)malloc(sizeof(struct node));
	struct node *pre = (struct node *)malloc(sizeof(struct node));
	root = string_to_linkedlist(input, root);
	if (root == NULL)
		return root;
	else
	{
		curr = root;
		while (curr != 0 && (curr->data % 2 == 1 || curr->data % 2 == -1))
		{
			curr = curr->next;
		}
		root = curr;
		pre = curr;
		if (curr != 0)
			curr = curr->next;
		while (curr != 0)
		{
			if (curr->data % 2 == 1 || curr->data % 2 == -1)
			{
				pre->next = curr->next;
				curr = pre->next;
			}
			else
			{
				pre = curr;
				curr = curr->next;
			}
		}
	}
	return root;
}
void dynamic_char(char *a, int i, char *input)
{
	int j = 0;
	for (j = 0; j < i; j++)
	{
		a[j] = input[j];
	}
	a[j] = '\0';
}

void testCases(struct node *root, struct node *input, struct node *output)
{
	int i;
	char *input_data, *output_data;
	for (i = 0; i<9; i++)
	{
		input_data = (char *)malloc(sizeof(int)*testDB[i].l1);
		output_data = (char *)malloc(sizeof(int)*testDB[i].l2);
		dynamic_char(input_data, testDB[i].l1, testDB[i].input);
		dynamic_char(output_data, testDB[i].l2, testDB[i].output);
		input = odd_remove(input_data, root);
		output = string_to_linkedlist(output_data, root);
		if (compare(input, output) == 0)
			printf("passed\n");
		else
			printf("failure\n");
	}
}
void main()
{
	struct node *root, *input, *output;
	root = (struct node *)malloc(sizeof(struct node));
	input = (struct node *)malloc(sizeof(struct node));
	output = (struct node *)malloc(sizeof(struct node));
	testCases(root, input, output);
	getch();
}