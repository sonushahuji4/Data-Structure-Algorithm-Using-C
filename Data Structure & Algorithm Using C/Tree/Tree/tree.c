#include<stdio.h>
#inlcude<stdlib.h>

struct node 
{

	struct node *left;
	char data[50];
	struct node *right;
};

struct node *start=NULL;

struct node *get_node()
{

	return (struct node*)malloc(sizeof(struct node));
}

void free_node(struct node *n)
{
	free(n);
}

int main()
{

	char a[50];
	int i,j;
	struct node *temp;
	printf("Enter Expression here:");
	gets(a);
	for(i=0; a[i]!=NULL; i++)
	{
		if(a[i]=='(' || a[i]=='{' || a[i]==)		
		temp=create(a[i]);
		
		temp=stack(a[50]);
	}
}

char create(char a[])
{
	struct node *new_node,*temp;
	new_node=get_node();
	new_node->data=a;
	if(start==NULL)
	{
		start=new_node;
		temp=start;
		temp->left=NULL;
		temp->right=NULL;
	}
	else
	{
		while(temp!=NULL)
		{
			temp=temp->next;
		}			
		temp->next=new_node;
		temp->data=a;
		temp->next=NULL;
		return(temp);
		
	}
}























