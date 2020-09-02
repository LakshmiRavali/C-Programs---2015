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
	int l1,k;
}testDB[9] = { { "1,2,3,4,5,6", "3,2,1,6,5,4", 11 ,3},
{ "-12,-13,-14", "-14,-13,-12", 15 ,3},
{ "1,2,3,3,4,5", "4,3,3,2,1,5", 9,5 },
{ "1", "1", 1 ,1},
{ "1,2", "2,1", 3,2 },
{ "1,2,3,4,5", "1,2,3,4,5" ,9,0},
{ "1,1,1", "1,1,1", 5,2 },
{ "1,2,3,4,5,6,7,8", "3,2,1,6,5,4,7,8",15,3 }
};
void testCases(struct node *, struct node *, struct node *);
struct node* string_to_linkedlist(char *, struct node *);
struct node* create(char *, struct node *);
struct node* insert(char *, struct node *);
int compare(struct node*, struct node *);
struct node* last_location(struct node *);
int calculation(char *, int);
struct node* reverse(struct node *);
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
	while (input->next != 0 || output->next != 0)
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
	if (root == 0)
		return 0;
	else
	{
		root = create(input, root);
		root = insert(input, root);
	}
	return root;
}
int length(struct node *head)
{
	int i = 0;
	while (head != 0)
	{
		head = head->next;
		i++;
	}
	return i;
}


struct node *reverse_k(struct node *head, int k)
{
	int i = 1;
	struct node *curr = (struct node *)malloc(sizeof(struct node*));
	struct node *last = (struct node *)malloc(sizeof(struct node*));
	if (head == NULL)
		return NULL;
	else if (head->next == 0)
		return head;
	else
	{
		curr = head->next;
		last = curr->next;
		if (head != 0 && head->next != 0)
		{
			head->next = 0;
			while (curr->next != 0 && i<k - 1)
			{
				curr->next = head;
				head = curr;
				curr = last;
				last = last->next;
				i++;
			}
			curr->next = head;
		}
	}
	head = last;
	return curr;
}

struct node* reverse(char *input, struct node  *head,int k)
{
	int l = 0,i=1;
	struct node *ptr1 = (struct node *)malloc(sizeof(struct node*));
	struct node *ptr2 = (struct node *)malloc(sizeof(struct node*));
	struct node *temp = (struct node *)malloc(sizeof(struct node*));
	head = string_to_linkedlist(input, head);
	if (head == NULL || head->next == 0||k==0)
		return head;
	else
	{
		temp = head;
		while (temp != 0 && i <= k)
		{
			temp = temp->next;
			i++;
		}
		l = length(head);
		if (l%k != 0)
			l = l - (l%k);
		while (l != 0)
		{
			ptr1 = reverse_k(head, k);
			l = l - k;
			if (l != 0)
			{
				head = temp;
				i = 0;
				while (temp != 0 && i < k)
				{
					temp = temp->next;
					i++;
				}
				ptr2 = reverse_k(head, k);
				l = l - k;
				head = ptr1;
				while (head != 0 && head->next != 0)
					head = head->next;
				head->next = ptr2;
				
			}
			head = temp;
		}
		if (head != 0 )
		{
			temp = ptr1;
			while (temp->next != 0)
				temp = temp->next;
			temp->next = head;
		}
	}
	return ptr1;
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
		input_data = (char *)malloc(sizeof(int)*testDB[i].l1);
		output_data = (char *)malloc(sizeof(int)*testDB[i].l1);
		dynamic_char(input_data, testDB[i].l1, testDB[i].input);
		dynamic_char(output_data, testDB[i].l1, testDB[i].output);
		input = reverse(input_data, root,testDB[i].k);
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