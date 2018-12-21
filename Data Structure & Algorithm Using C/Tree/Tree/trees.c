#include<stdio.h>
#include<stdlib.h>

struct node 
{
	struct node *left;
	char data;
	struct node *right;
};

struct node *start=NULL;
char stack[50];
int top=-1;

char pop();
char push(struct node *new_node);
void operator(char x);
void aprand(char a);
void display();

int check(char a);

struct node *getnode()
{
	return(struct node*)malloc(sizeof(struct node));
}

int main()
{
	char str[30];
	int i,j,k,temp;
	printf("Enter Expression:\n");
	gets(str);
	for(i=0; str[i]!=NULL; i++)
	{
		temp=check(str[i]);
		if(temp==1)
		{
			operator(str[i]);
		}
		else
		{
			aprand(str[i]);
		}
	}
	printf("");
}

int check(char a)
{
	if(a=='+' || a=='-' || a=='*' || a=='/')
	{
		return 1;
	}
	else
	{
		return 2;
	}

}

void operator(char x)
{
	struct node *new_node;
	new_node=getnode();
	new_node->data=x;
	new_node->left=pop();
	new_node->right=pop();
	push(new_node);
}

void aprand(char a)
{
	struct node *new_node;
	new_node=getnode();
	new_node->data=a;
	new_node->left=NULL;
	new_node->right=NULL;
	push(new_node);
}

char push(struct node *new_node)
{
	stack[top++]=new_node;
}

char pop()
{
	return stack[top--];
}

void display(struct node *temp)
{

	if(temp!=NULL)
	{
		display(temp->left);
		printf("%c",temp->left);
		display(temp->right);
		
	}
	
}







