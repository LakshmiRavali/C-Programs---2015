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
	int l, m;
}testDB[9] = { { "1,2,3,4,5,6,7", "1,2,5,4,3,6,7",13,3 },
{"1,2,3,4,5,6,7,8,9","1,8,3,4,5,6,7,2,9",17,8},
{ "12,13,14,15,16,17", "12,16,14,15,13,17", 18, 2 },
{ "1,2,3", "3,2,1", 5, 3 },
{ "1,2,3,3,4,5", "1,2,3,3,4,5", 11, 0 },
{ "", "", 0, 0 },
{ "-1,-2,-3,-4,-5,-6,-7", "-1,-2,-5,-4,-3,-6,-7",20,3 }
};
void testCases(struct node *, struct node *, struct node *);
struct node* string_to_linkedlist(char *, struct node *);
struct node* create(char *, struct node *);
struct node* insert(char *, struct node *);
int compare(struct node*, struct node *);
int calculation(char *, int);
struct node* swap_ll(char *, struct node *, int, int);
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
	if (input[0] == '\0')
		return 0;
	else
	{
		root = create(input, root);
		root = insert(input, root);
	}
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
struct node* remove_fun(char *input, struct node *root, int m)
{
	int i=1,l;
	struct node *last = (struct node *)malloc(sizeof(struct node));
	struct node *curr = (struct node *)malloc(sizeof(struct node));
	struct node *first = (struct node *)malloc(sizeof(struct node));
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	root = string_to_linkedlist(input, root);
	l = length(root);
	first = root;
	if (root == NULL)
		return NULL;
	else if (m == (l / 2 + 1)||m==0)
		return root;
	else
	{
		while (i<m-1 && first!=0)
		{
			first = first->next;
			i++;
		}
		last = first->next;
		curr = root;
		while (last!=0&&last ->next!= 0&&last->next->next!=0)
		{
			last = last->next;
			curr = curr->next;
		}
		
		if (m < (l / 2 + 1))
		{
			temp = first->next;
			last = curr;
			curr = curr->next;
			last->next = curr->next;
			curr->next = temp->next;
			first->next = curr;
			temp->next = last->next;
			last->next = temp;
		}
		else if (m > (l / 2 + 1))
		{
			temp = first;
			first = first->next;
			if (first != last||last->next!=0)
			{
				last = curr->next;
				temp->next = first->next;
				first->next = last->next;
				curr->next = first;
				last->next = temp->next;
				temp->next = last;
			}
			else
			{
				temp = last->next;
				last->next = curr->next;
				curr->next->next = curr;
				curr->next = temp;
				root = last;
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
	for (i = 0; i<7; i++)
	{
		input_data = (char *)malloc(sizeof(int)*testDB[i].l);
		output_data = (char *)malloc(sizeof(int)*testDB[i].l);
		dynamic_char(input_data, testDB[i].l, testDB[i].input);
		dynamic_char(output_data, testDB[i].l, testDB[i].output);
		input = remove_fun(input_data, root, testDB[i].m);
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