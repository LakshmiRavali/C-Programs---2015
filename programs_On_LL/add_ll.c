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
	char input1[20],input2[20], output[20];
	int l1,l2,l3;
}testDB[7] = { { "5,2,3", "1,2,3","6,4,6" ,5,5,5 },
{ "1,2,3,4", "1,2,3","2,4,6,4",7,5,7 },
{ "1,9,7", "1,9,7,1", "2,8,5,2", 5,7,7},
{ "9,2,3", "3,2,9", "2,5,2,1", 5,5,7 },
{ "1,2,3", "", "1,2,3",5,0,5 },
{ "", "1,1","1,1",0,3,3 },
};
void testCases(struct node *, struct node *, struct node *);
struct node* string_to_linkedlist(char *, struct node *);
struct node* create(char *, struct node *);
struct node* insert(char *, struct node *);
int compare(struct node*, struct node *);
int calculation(char *, int);
struct node* add_ll(char *, struct node *, struct node *);
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
struct node* string_to_linkedlist(char *input)
{
	struct node *root = (struct node *)malloc(sizeof(struct node));
	if (input[0] == '\0')
		root = 0;
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
struct node* add_ll(struct node *root,char *a,char *b)
{
	int r,c=0,i=0;
	struct node *i1 = (struct node *)malloc(sizeof(struct node));
	struct node *i2 = (struct node *)malloc(sizeof(struct node));
	struct node *i3 = (struct node *)malloc(sizeof(struct node));
	i1 = string_to_linkedlist(a);
	i2 = string_to_linkedlist(b);
	if (i1 == 0&&i2 == 0)
	{
		return "";
	}
	else if (i1 == 0)
		return i2;
	else if (i2 == 0)
		return i1;
	else
	{
		while (i1 != 0&&i2 != 0)
		{
			struct node *temp = (struct node *)malloc(sizeof(struct node));
			r = (i1->data + i2->data) + c;
			if (r > 9)
			{
				r = r % 10;
				c = 1;
			}
			else
				c = 0;
			temp->next = 0;
			temp->data = r;
			if (i == 0)
			{
				i3 = temp;
				root = i3;
				i = 1;
			}
			else
			{
				i3->next = temp;
				i3 = temp;
			}
			i1 = i1->next;
			i2 = i2->next;
		}
		if (i1 != 0)
		{
			while (i1 != 0)
			{
				struct node *temp = (struct node *)malloc(sizeof(struct node));
				r = i1->data + c;
				if (r > 9)
				{
					r = r % 10;
					c = 1;
				}
				else
					c = 0;
				temp->next = 0;
				temp->data = r;
				if (i == 0)
				{
					i3 = temp;
					root = i3;
					i = 1;
				}
				else
					i3->next = temp;
				i1 = i1->next;
			}
		}
		else if (i2 != 0)
		{
			while (i2 != 0)
			{
				struct node *temp = (struct node *)malloc(sizeof(struct node));
				r = i2->data + c;
				if (r > 9)
				{
					r = r % 10;
					c = 1;
				}
				else
					c = 0;
				temp->next = 0;
				temp->data = r;
				if (i == 0)
				{
					i3 = temp;
					root = i3;
					i = 1;
				}
				else
				{
					i3->next = temp;
					i3 = temp;
				}
				i2 = i2->next;
			}
		}
		if (c != 0)
		{
			struct node *temp = (struct node *)malloc(sizeof(struct node));
			temp->next = 0;
			temp->data = c;
			i3->next = temp;
			i3 = temp;
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

void testCases(struct node *root, struct node *input1, struct node *output)
{
	int i;
	char *input1_data,*input2_data, *output_data;
	for (i = 0; i<6; i++)
	{
		input1_data = (char *)malloc(sizeof(int)*testDB[i].l1);
		input2_data = (char *)malloc(sizeof(int)*testDB[i].l2);
		output_data = (char *)malloc(sizeof(int)*testDB[i].l3);
		dynamic_char(input1_data, testDB[i].l1, testDB[i].input1);
		dynamic_char(input2_data, testDB[i].l2, testDB[i].input2);
		dynamic_char(output_data, testDB[i].l3, testDB[i].output);
		input1 = add_ll(root,input1_data, input2_data);
		output = string_to_linkedlist(output_data);
		if (compare(input1, output) == 0)
			printf("passed\n");
		else
			printf("failure\n");
	}
}
void main()
{
	struct node *root, *input1 ,*output;
	root = (struct node *)malloc(sizeof(struct node));
	input1 = (struct node *)malloc(sizeof(struct node));
	output = (struct node *)malloc(sizeof(struct node));
	testCases(root, input1, output);
	getch();
}