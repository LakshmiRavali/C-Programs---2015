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
	char input[20],output[30];
	int k,l1;
}testDB[7]={{"12,13,14","12,13,2,14",2,8},
{"1,2,3,4","1,2,2,3,4,2",2,9},
{"1,2,4,5,6,7","1,2,4,3,5,6,7,3",3,15},
{"1,2","1,2",5,3},
{"1,2,3,4,5,6,7,8,9","1,2,3,4,4,5,6,7,8,4,9",4,22},
{"1","1,1",1,3},
{"1","1",5,3}
};
void testCases(struct node *,struct node *,struct node *);
struct node* string_to_linkedlist(char *,struct node *);
struct node* create(char *,struct node *);
struct node* insert(char *,struct node *);
int compare(struct node*,struct node *);
struct node* last_location(struct node *);
int calculation(char *,int );
struct node* insert_kthposition(char *,struct node *,int);
void insersion(struct node*,struct node*,int);
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
	return root;
}
void insersion(struct node *slow,struct node *fast,int k)
{
	int i=0;
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	while(i<k-1&&fast->next!=0&&slow->next!=0)
	{
		slow=slow->next;
		fast=fast->next;
		i++;
	}
	temp->data=k;
	temp->next=0;
	if(slow->next==0&&k==1)
		slow->next=temp;
	else if(fast->next==0)
	{
		if(i==k-1)
		{
		slow->next=temp;
		temp->next=fast;
		}
		else if(i+1==k-1)
			fast->next=temp;
	}
	else if(slow->next!=0&&fast->next!=0)
	{
		slow->next=temp;
		temp->next=fast;
		insersion(fast,fast->next,k);
	}
}
struct node* insert_kthposition(char *input,struct node *root,int k)
{
	struct node *slow=(struct node *)malloc(sizeof(struct node));
	root=string_to_linkedlist(input,root);
	if(root==NULL)
		return NULL;
	else if(root->next==NULL)
	{
		if(k==1)
		{
			slow->data=k;
			slow->next=0;
			root->next=slow;
			return root;
		}
		else
			return root;
	}
	else
	{
		insersion(root,root->next,k);
	}
	return root;
}

void testCases(struct node *root,struct node *input,struct node *output)
{
	int i;
	for(i=0;i<7;i++)
	{
		input=insert_kthposition(testDB[i].input,root,testDB[i].k);
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