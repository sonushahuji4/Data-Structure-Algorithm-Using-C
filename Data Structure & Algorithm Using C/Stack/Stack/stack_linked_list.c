#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *temp=NULL,*top=NULL;

void *getnode()
{
	return (struct node*)malloc(sizeof(struct node));
}

void freenode(struct node *n)
{
	free(n);
}
void exit();

void push()
{
	struct node *new_node;
	if(temp==NULL)
	{
			new_node=getnode();
			printf("Enter data:");
			scanf("%d",&new_node->data);
			top=new_node;
			new_node->next=NULL;
			temp=top;
	}
	else
	{
		new_node=getnode();
		printf("Enter data:");
		scanf("%d",&new_node->data);
		new_node->next=top;
		top=new_node;
	}
}

void pop()
{
	if(top==NULL)
	{
		printf("\n\t\t\tstack Underflow");
	}
	else
	{
		temp=top;
		top=top->next;
		free(temp);
	}
}

void display()
{
	
	if(top==NULL)
	{
		printf("\n\t\t\tstack Underflow");
	}
	else
	{
		printf("data display\n");
		while(top->next!=NULL)
		{
			printf("%d\t",top->data);
			top=top->next;
		}
		printf("%d\t",top->data);
	}
}

void main()
{
	int choice;
	do
	{
		printf("\n\n\t\t\tStack \tArray \tMenu \tDriven \tProgramme\n\n");
		printf("\n\t\t\t1.Push\n\t\t\t2.Pop\n\t\t\t3.Display\n\t\t\t4.Exit\n");
		printf("\n\t\t\tEnter your choice:");
		scanf("\t\t\t%d",&choice);
		switch(choice)
		{
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:display();
			break;
			case 4: exit(0.);
			default : printf("\n\t\t\t\t\tWRONG CHOICE");
		}
	}while(choice!=4);
}