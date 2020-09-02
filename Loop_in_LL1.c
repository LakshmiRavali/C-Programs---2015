#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
struct node
{
	int data,k;
	struct node *next;
};
struct test
{
	char input[20],output[30];
	int k,l1;
}testDB[6]={{"12,13,14,15","Yes",2,8},
{"1,2,3,4","Yes",3,9},
{"1,2,4,5,6,7","no",0,15},
{"1","no",0,1},
{"1,1,1","Yes",2,5},
{"1,2,4,5","Yes",1,7},
};
void testCases(struct node *);
struct node* string_to_linkedlist(char *,struct node *,int);
struct node* create(char *,struct node *);
struct node* insert(char *,struct node *);
int compare(char *,char *);
int calculation(char *,int );
struct node* delete_kthposition(char *,struct node *,int);
void Loop_detection(struct node *,int);
char* Is_Loop(char *,struct node *);
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
int compare(char *input,char *output)
{
	int i=0;
	while(input[i]!=0||output[i]!=0)
	{
		if(input[i]!=output[i])
			return 1;
	i++;
	}
	return 0;
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
struct node* last_location(struct node *root)
{
	while(root->next!=0)
		root=root->next;
	return root;
}
void Loop_detection(struct node *root,int k)
{
	int i=0;
	struct node *last=(struct node *)malloc(sizeof(struct node));
	last=last_location(root);
	while(i!=k-1&&k>0)
	{
		root=root->next;
		i++;
	}
	if(k>0)
		last->next=root;
	else
		last->next=0;
}
struct node* string_to_linkedlist(char *input,struct node *root,int k)
{
	root=create(input,root);
	root=insert(input,root);
	Loop_detection(root,k);
	return root;
}
char *Is_Loop(char *input,struct node *root)
{
	if(root==NULL)
		return "no";
	else
	{
		while(root->next!=0)
		{
			if(root->k==1)
				return "Yes";
			root->k=1;
			root=root->next;
		}
	}
	return "no";
}
void testCases(struct node *root)
{
	int i;
	char *input;
	for(i=0;i<6;i++)
	{
		root=string_to_linkedlist(testDB[i].input,root,testDB[i].k);
		input=Is_Loop(testDB[i].input,root);
		if(compare(input,testDB[i].output)==0)
			printf("passed\n");
		else
			printf("failure\n");
	}
}
void main()
{
	struct node *root,*input,*output;
	 root=(struct node *)malloc(sizeof(struct node));
	testCases(root);
	getch();
}