#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL,*front=NULL,*rear=NULL;

void *getnode()
{
	return (struct node*)malloc(sizeof(struct node));
}

void freenode(struct node *n)
{
	free(n);
}
void exit();

void insert_Q()
{
	struct node *new_node;
	if(front==NULL)
	{
		new_node=getnode();
		printf("\n\t\t\tEnter data:");
		//printf("\t\t\t");
		scanf("%d",&new_node->data);
		new_node->next=NULL;
		front=new_node;
		rear=new_node;
	}
	else
	{
		rear->next=getnode();
		rear=rear->next;
		printf("\n\t\t\tEnter data:");
		scanf("%d",&rear->data);
		rear->next=NULL;
	}
}
void delete_Q()
{
	struct node *temp;
	temp=front;
	if(front==NULL && rear==NULL)
	{
		printf("\n\t\t\t\t\t!!!!....Q_Underflow....!!!!\n");
	}
	else if(front==rear)
	{
		front=NULL;
		rear=NULL;
		printf("\n\t\t\t>>..%d is deleted successfully..!!\n", temp->data);
		free(temp);
	}
	else
	{
		front=front->next;
		printf("\n\t\t\t>>..%d is deleted successfully..!!\n", temp->data);
		free(temp);
	}
}

void display()
{
	struct node *temp;
	temp=front;
	if(front==NULL)
	{
		printf("\n\t\t\t\t\t!...........List Underflow...........!\n");
	}
	else
	{
		printf("\n\n\t\t\t\t\t>>>>>>>>:-----Data Display-----:<<<<<<<<<\n");
		while(temp!=NULL)
		{
			printf("\t\t\t");
			printf("%d\n",temp->data);
			temp=temp->next;
		}
		
	}
}
void main()
{
		int ch;
	do
	{
		printf("\n\t\t\t\t\tQ_Linked_List_Menu Driven Programme\n");
		printf("\n\n\t\t\t\t\t\t!..H..O..M..E..!\n");
		printf("\n\t\t\t1.Insert_Q\n\t\t\t2.Delete_Q\n\t\t\t3.Display_Q\n\t\t\t4.Exit\n");
		printf("\n\t\t\tEnter your choice here:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert_Q();
					break;
			case 2: delete_Q();
					break;
			case 3: display();
					break;
			case 4: exit(0);
			
			default: printf("\n\t\t\t\tOpps wrong choice..!!\n");
		}
	}while(ch!=4);
}