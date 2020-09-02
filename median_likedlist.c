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
	char input[20];
	float output;
	int l1;
}testDB[5]={{"12,13,14",13,8},
{"-12,-13,-14",-13,15},
{"1,2,3,3,4,5",3,9},
{"1,2,3,4",2.5,7},
{"-89,-43,-1,0,1",-1,15}
};
void testCases(struct node *);
struct node* string_to_linkedlist(char *,struct node *);
struct node* create(char *,struct node *);
struct node* insert(char *,struct node *);
int compare(struct node*,struct node *);
struct node* last_location(struct node *);
int calculation(char *,int );
float median(char *,struct node *);
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
float median(char *input,struct node *root)
{
	int k=1,j=0;
	float x,y,z;
	struct node* last;
	last=(struct node*)malloc(sizeof(struct node));
	root=string_to_linkedlist(input,root);
	last=root;
	while(last->next!=0)
	{
		last=last->next;
		k++;
	}
	if(k==0)
		return 0;
	else if(k%2==1)
	{
	while(j<k/2)
	{
		root=root->next;
		j++;
	}
	z=root->data;
	}
	else
	{
		while(j<(k/2-1))
	{
		root=root->next;
		j++;
	}
		x=root->data;
		root=root->next;
		y=root->data;
		z=(x+y)/2;
	}
	return z;

}

void testCases(struct node *root)
{
	int i;
	float res;
	for(i=0;i<5;i++)
	{
		res=median(testDB[i].input,root);
		if(res==testDB[i].output)
			printf("passed\n");
		else
			printf("failure\n");
	}
}
void main()
{
	struct node *root;
	root=(struct node *)malloc(sizeof(struct node));
	testCases(root);
	getch();
}