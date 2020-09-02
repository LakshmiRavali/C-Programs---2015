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
	char input[20],output[4];
	int l1;
}testDB[4]={{"12,13,13,12","Yes",11},
{"1,2,3,2,1","Yes",9},
{"1,2,4,5,6,7","no",11},
{"1","Yes",1},
};
void testCases(struct node *);
struct node* string_to_linkedlist(char *,struct node *);
struct node* create(char *,struct node *);
struct node* insert(char *,struct node *);
int compare(char *,char *);
int calculation(char *,int );
struct node* delete_kthposition(char *,struct node *,int);
char* Palindrome(char *,struct node *);
void dynamic_char(char *,int ,char *);
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
int last_location(struct node *root)
{
	int k=0;
	while(root->next!=0)
	{
		root=root->next;
		k++;
	}
	return k;
}
struct node* reverse(struct node  *head)
{
	struct node *curr=(struct node *)malloc(sizeof(struct node*));
	struct node *last=(struct node *)malloc(sizeof(struct node*));
	curr=head->next;
	last=curr->next;
	if(head!=0&&head->next!=0)
	{
		head->next=0;
		while(curr->next!=0)
		{
			curr->next=head;
			head=curr;
			curr=last;
			last=last->next;
		}
		curr->next=head;
	}
	return curr;
}

struct node* string_to_linkedlist(char *input,struct node *root)
{
	root=create(input,root);
	root=insert(input,root);
	return root;
}
char *Palindrome(char *input,struct node *root)
{
	struct node *rev=(struct node *)malloc(sizeof(struct node));
	root=string_to_linkedlist(input,root);
	if(root==NULL)
		return NULL;
	else if(root->next==0)
		return "Yes";
	else
	{
		rev=reverse(root);
		root=string_to_linkedlist(input,root);
		while(root->next!=0)
		{
			if(root->data!=rev->data)
				return "no";
			root=root->next;
			rev=rev->next;
		}
	}
	return "Yes";
}
void dynamic_char(char *a,int i,char *input)
{
	int j=0;
	while(input[j]!='\0')
	{
		a[j]=input[j];
		j++;
	}
	a[j]='\0';
}
void testCases(struct node *root)
{
	int i;
	char *input;
	for(i=0;i<4;i++)
	{
		input=(char *)malloc(sizeof(int)*testDB[i].l1);
		dynamic_char(input,testDB[i].l1,testDB[i].input);
		input=Palindrome(testDB[i].input,root);
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
