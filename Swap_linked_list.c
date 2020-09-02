#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
struct node
{
	char data;
	struct node *next;
};
struct test
{
	char input[20],output[20];
	int l1;
}testDB[5]={{"a,b,c,d,e,f,g","b,a,d,c,f,e,g",12},
{"a","a",1},
{"a,b","b,a",3},
{"1,2,3","2,1,3",6},
};
void testCases(struct node *,struct node*);
struct node* string_to_linkedlist(char *,struct node *);
struct node* create(char *,struct node *);
struct node* insert(char *,struct node *);
int compare(struct node*,struct node *);
struct node* last_location(struct node *);
struct node* swaplist(struct node*,struct node *,struct node*);
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
	temp->next=0;
	temp->data=input[0];
	root=temp;
	return root;
}
struct node* insert(char *input,struct node *root)
{
	int value,i=2,j;
	struct node *curr=(struct node *)malloc(sizeof(struct node));
	curr=root;
	while(input[i]!=0)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		temp->next=0;
		temp->data=input[i];
		curr->next=temp;
		curr=temp;
		i=i+2;

	}
	curr->next=0;
	return root;
}
struct node* string_to_linkedlist(char *input,struct node *root)
{
	struct node *slow,*fast,*temp;
	root=create(input,root);
	root=insert(input,root);
	slow=(struct node*)malloc(sizeof(struct node));
	fast=(struct node*)malloc(sizeof(struct node));
	temp=(struct node*)malloc(sizeof(struct node));
	slow=root;
	fast=root->next;
	root=swaplist(slow,fast,temp);
	return root;
}
struct node* swaplist(struct node *slow,struct node *fast,struct node *temp)
{
	if(slow==NULL)
		return 0;
	else if(slow->next==NULL)
		return slow;
	else if(fast->next==NULL)
	{
		fast->next=slow;
		slow->next=NULL;
		return fast;
	}
	else
	{
		temp=swaplist(slow->next->next,fast->next->next,temp);
		slow->next=temp;
		fast->next=slow;
	}
	return fast;
}

void testCases(struct node *root,struct node *res_input,struct node *output)
{
	int i;
	for(i=0;i<4;i++)
	{
		res_input=string_to_linkedlist(testDB[i].input,root);
		root=create(testDB[i].output,root);
		output=insert(testDB[i].output,root);
		if(compare(res_input,output)==0)
			printf("passed\n");
		else
			printf("failed\n");
	}
}
void main()
{
	struct node *root,*res_input,*output;
	root=(struct node *)malloc(sizeof(struct node));
	res_input=(struct node *)malloc(sizeof(struct node));
	output=(struct node *)malloc(sizeof(struct node));
	testCases(root,res_input,output);
	getch();
}