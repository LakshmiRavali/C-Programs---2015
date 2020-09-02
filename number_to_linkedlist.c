#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct test
{
	int input,l;
	char output[20];
}testDB[5]={{1234,4,{"1,2,3,4"}},
{0,0,{"0"}},
{-1234,5,{"-1,2,3,4"}},
{-1,2,{"-1"}},
};

struct node
{
	int data;
	struct node *next;
};
int compare(struct node *,struct node *);
void testCases(struct node *,struct node *,struct node *);
struct node *create(int,struct node *);
struct node* insert_num(int,struct node *,struct node*);
struct node* create1(char *,struct node*);
struct node* last_location(struct node*);
int calculation(char *,int);
struct node* insert(char *,struct node*);
struct node* string_to_linkedlist(char *,struct node *);
struct node* last_location(struct node *root)
{
	while(root->next!=0)
		root=root->next;
	return root;
}
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
struct node* create1(char *input,struct node *root)
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
	root=create1(input,root);
	root=insert(input,root);
	return root;
}
struct node* create(int num,struct node *first)
{
	int res,dup;
	struct node *temp,*last;
	temp=(struct node*)malloc(sizeof(struct node));
	last=(struct node*)malloc(sizeof(struct node));
	dup=num;
	temp->next=0;
	temp->data=num%10;
	num=num/10;
	first=temp;
	last=temp;
	first=insert_num(num,first,last);
	last=first->next;
	if(dup<0&&last!=0)
	{
		while(last->next!=0)
		{
			last->data=-last->data;
			last=last->next;
		}
	}
	return first;
}
struct node* insert_num(int num,struct node *first,struct node *last)
{
	while(num!=0)
	{
		struct node *curr;
		curr=(struct node*)malloc(sizeof(struct node));
		curr->data=num%10;
		num=num/10;
		curr->next=last;
		last=curr;
	}
	return last;
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
void testCases(struct node *root,struct node *input,struct node *output)
{
	int i;
	for(i=0;i<4;i++)
	{
		input=create(testDB[i].input,root);
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



