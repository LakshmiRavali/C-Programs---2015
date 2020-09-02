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
	char input[20],output[20];
	int l1;
}testDB[5]={{"12,13,14","14,13,12",8},
{"-12,-13,-14","-14,-13,-12",15},
{"1,2,3,3,4,5","5,4,3,3,2,1",9},
{"1","1",1},
{"1,2","2,1",3},
};
void testCases(struct node *,struct node *,struct node *);
struct node* string_to_linkedlist(char *,struct node *);
struct node* create(char *,struct node *);
struct node* insert(char *,struct node *);
int compare(struct node*,struct node *);
struct node* last_location(struct node *);
int calculation(char *,int );
struct node* reverse(struct node *);
int calculation(char *input,int i)
{
	int j=0,p=1,value=0;
		p=1;
		value=0;
		while(i>=0&&input[i]!=',')
		{
			if(input[i]!='-')
			{
				value=value+(input[i]-48)*p;
				p=p*10;
			}
			else
				value=(-value);
		i--;
		}
		return value;
}
int compare(struct node* input,struct node* output)
{
	while(input->next!=0||output->next!=0)
	{
		if(input->data!=output->data)
			return 1;
	input=input->next;
	output=output->next;
	}
	return 0;
}
struct node* last_location(struct node *root)
{
	while(root->next!=0)
		root=root->next;
	return root;
}
struct node* create(char *input,struct node *root)
{
	int value,i=0;
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	while(input[i]!=','&&input[i]!='\0')
			i++;
		i--;
	value=calculation(input,i);
	temp->next=0;
	temp->data=value;
	root=temp;
	return root;
}
struct node* insert(char *input,struct node *root)
{
	int value,i=0,j;
	struct node *curr=(struct node *)malloc(sizeof(struct node));
	curr=last_location(root);
	curr=root;
	while(input[i]!=','&&input[i]!='\0')
		i++;
	i++;
	while(input[i]!=','&&input[i]!='\0')
		i++;
	i--;
	while(input[i]!='\0'&&input[i-2]!='\0')
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		while(input[i]!=','&&input[i]!='\0')
			i++;
		j=i+1;
		i--;
		value=calculation(input,i);
		temp->next=0;
		temp->data=value;
		curr->next=temp;
		curr=temp;
		i=j;
	}
	curr->next=0;
	return root;
}
struct node* string_to_linkedlist(char *input,struct node *root)
{
	root=create(input,root);
	root=insert(input,root);
	root=reverse(root);
	return root;
}
struct node* reverse(struct node  *head)
{
	if(head == NULL)
		return NULL;
	else if(head->next == NULL)
		return head;
	else
	{
		struct node *temp = reverse(head->next);
		head->next = NULL;
		temp->next = head;
		return head;
	}
}

void testCases(struct node *root,struct node *input,struct node *output)
{
	int i;
	for(i=0;i<5;i++)
	{
		input=string_to_linkedlist(testDB[i].input,root);
		output=string_to_linkedlist(testDB[i].output,root);
		if(compare(input,output)==0)
			printf("passed\n");
		else
			printf("failure\n");
	}
}
void main()
{
	struct node *root,*input,*output;
	 root=(struct node *)malloc(sizeof(struct node));
	 input=(struct node *)malloc(sizeof(struct node));
	 output=(struct node *)malloc(sizeof(struct node));
	testCases(root,input,output);
	getch();
}