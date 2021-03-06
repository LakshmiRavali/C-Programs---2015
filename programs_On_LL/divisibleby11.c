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
	char input[20], output[5];
	int l1, l2;
}testDB[9] = { { "1,2,1", "True", 5, 4 },
{ "1,3,2", "True", 5, 4 },
{ "1,2,3", "False", 5, 5 },
{ "3,3", "True", 3, 4 },
{ "1,3,5,7", "False", 7, 5 },
{ "1", "False", 1, 5 },
{ "1,0,5,6", "True", 7, 4 },
{ "6,1,0,5", "True",7,4 },
};
void testCases(struct node *, struct node *, struct node *);
struct node* string_to_linkedlist(char *, struct node *);
struct node* create(char *, struct node *);
struct node* insert(char *, struct node *);
int compare(struct node*, struct node *);
int calculation(char *, int);

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
int compare(char* input, char* output)
{
	int i = 0;
	while (input[i] != 0 && output[i] != 0)
	{
		if (input[i] != output[i])
			return 1;
		i++;
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
	while (input[i] != ','&&input[i] != '\0'&&input[i - 1] != '\0')
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
	root = create(input, root);
	root = insert(input, root);
	return root;
}
int length(struct node *a)
{
	int l = 0;
	while (a != NULL)
	{
		a = a->next;
		l++;
	}
	return l;
}
char* divisible_by_11(char *input, struct node *root)
{
	int even_sum=0,odd_sum=0,i=0;
	struct node *curr = (struct node *)malloc(sizeof(struct node));
	root = string_to_linkedlist(input, root);
	curr = root;
	if (root == NULL)
		return root;
	else
	{
		while (curr != 0)
		{
			if (i % 2 == 0)
				even_sum = even_sum + curr->data;
			else
				odd_sum = odd_sum + curr->data;
			curr = curr->next;
			i++;
		}
	}
		
	if (even_sum==odd_sum)
		return "True";
	else
		return "False";
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

void testCases(struct node *root)
{
	int i;
	char *input_data, *output_data;
	for (i = 1; i<9; i++)
	{
		input_data = (char *)malloc(sizeof(int)*testDB[i].l1);
		output_data = (char *)malloc(sizeof(int)*testDB[i].l2);
		dynamic_char(input_data, testDB[i].l1, testDB[i].input);
		dynamic_char(output_data, testDB[i].l2, testDB[i].output);
		input_data = divisible_by_11(input_data, root);
		if (compare(input_data, output_data) == 0)
			printf("passed\n");
		else
			printf("failure\n");
	}
}
void main()
{
	struct node *root;
	root = (struct node *)malloc(sizeof(struct node));
	testCases(root);
	getch();
}