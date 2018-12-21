#include<stdio.h>
#include<stdlib.h>
struct node
{
		int data;
		struct node *next;
};
struct node *temp=NULL,*front=NULL,*rear=NULL;
void *getnode()
{
		return(struct node*)malloc(sizeof(struct node));
}

void freenode(struct node *n)
{
	free(n);
}
void input_restricted();
void output_restricted();
void insert_front();
void delete_front();
void delete_end();
void insert_end();
void home();
void display();

void display()
{
	struct node *temp;
	temp=front;
	if(front==NULL)
	{
		printf("\n\t\t\t\t!!....List Underflow....!!\n");
	}
	else
	{
		printf("\n\n\t\t\t>>>>>>>>>>....Data Display....<<<<<<<<<<\n");
			while(temp!=NULL)
			{
				printf("\n\t\t\t\t\t%d\n",temp->data);
				temp=temp->next;
			}
	}
}

void insert_front()
{
	struct node *new_node;
	new_node=getnode();
	printf("\n\t\t\t\tEnter the data:\n");
	printf("\t\t\t\t\t");
	scanf("%d",&new_node->data);
	new_node->next=NULL;
	if(temp==NULL)
	{
		temp=new_node;
		front=temp;
		rear=front;
	}
	else
	{
		new_node->next=front;
		front=new_node;
		temp=new_node;
	}
}

void delete_front()
{
	int num;
	struct node *move;
	if(front==NULL)
	{
		printf("\n\t\t\t\t!!....List Underflow....!!\n");
	}
	else
	{
		if(front==rear)
		{
			move=front;
			num=front->data;
			front=NULL;
			rear=NULL;
			free(move);
			printf("\n\t\t\t\t%d is deleted successfully..!\n",num);
		}
		else
		{
			move=front;
			num=front->data;
			front=front->next;
			free(move);
			printf("\n\t\t\t\t%d is deleted successfully..!!\n",num);
		}
	}
}

void delete_end()
{
	struct node *move;
	int num;
	temp=front;
	if(rear==NULL)
	{
		printf("\n\t\t\t\t!!....List Underflow....!!");
	}
	else
	{
		if(front==rear)
		{
			move=front;
			num=front->data;
			front=NULL;
			rear=NULL;
			free(move);
			printf("\n\t\t\t\t%d is deleted successfully..!!\n",num);
		}
		else
		{
			while(temp->next!=rear)
			{
				temp=temp->next;
			}
			rear=temp;
			temp=temp->next;
			move=temp;
			num=temp->data;
			free(move);
			printf("\n\t\t\t\t%d is deleted successfully..!!\n",num);
		}
	}
}

void insert_end()
{
	struct node *new_node;
	new_node=getnode();
	printf("\n\t\t\t\tEnter the data:");
	scanf("%d",&new_node->data);
	new_node->next=NULL;
	if(front==NULL && rear==NULL)
	{
		temp=new_node;
		front=temp;
		rear=front;
	}
	else
	{
		rear->next=new_node;
		rear=rear->next;
	}
}
void main()
{
int option;
	do
	{
		printf("\n\t\t\t\tDeque Menu Driven Programme\n\n");
		printf("\n\t\t\t\t!..H..O..M..E..!\n");
		printf("\n\t\t\t1.Input restricted\n\t\t\t2.Output restricted\n\t\t\t3.Exit\n");
		printf("\n\t\t\tEnter your choice:");
		scanf("%d",&option);
		switch(option)
		{
			case 1: input_restricted();
					break;
			case 2: output_restricted();
					break;
			case 3: exit(0);
			default: printf("Are you sure, you want to Exit");
		}
	}while(option!=3);
}

void input_restricted()
{
	int option;
	do
	{
		printf("\n\t\t\t\tInput Restriction page\n\n");
		printf("\n\t\t\t1.Insert at Front\n\t\t\t2.Delete at Front\n\t\t\t3.Delete at End\n\t\t\t4.Display\n\t\t\t5.Back to Home page\n\t\t\t6.Move to Output Restricted page\n\t\t\t7.Exit\n");
		printf("\n\t\t\tEnter your choice:");
		scanf("%d",&option);
		switch(option)
		{
			case 1: insert_front();
					break;
			case 2: delete_front();
					break;
			case 3: delete_end();
					break;
			case 4: display();
					break;
			case 5: main();
					break;
			case 6: output_restricted();
					break;
			case 7: exit(0);
			default: printf("Programme Terminates");
		}
	}while(option!=7);
}


void output_restricted()
{
	int option;
		do
	{
		printf("\n\t\t\t\tOutput Restriction page\n\n");
		printf("\n\t\t\t1.Delete at Front\n\t\t\t2.Insert at Front\n\t\t\t3.Insert at End\n\t\t\t4.Display\n\t\t\t5.Back to Home page\n\t\t\t6.Move to Input Restricted page\n\t\t\t7.Exit\n");
		printf("\n\t\t\tEnter your choice:");
		scanf("%d",&option);
		switch(option)
		{
			case 1: delete_front();
					break;
			case 2: insert_front();
					break;
			case 3: insert_end();
					break;
			case 4: display();
					break;
			case 5: main();
					break;
			case 6: input_restricted();
					break;
			case 7: exit(0);
			default: printf("Programme Terminates");
		}
	}while(option!=7);
}




/*										>>>>>>>>>..............OUTPUT............<<<<<<<<			

												Microsoft Windows [Version 6.1.7601]
Copyright (c) 2009 Microsoft Corporation.  All rights reserved.

C:\Users\sonu shahuji>color A

C:\Users\Sonu shahuji>D:

D:\>gcc dq.c

D:\>a

                                Deque Menu Driven Programme


                                !..H..O..M..E..!

                        1.Input restricted
                        2.Output restricted
                        3.Exit

                        Enter your choice:1

                                Input Restriction page


                        1.Insert at Front
                        2.Delete at Front
                        3.Delete at End
                        4.Display
                        5.Back to Home page
                        6.Move to Output Restricted page
                        7.Exit

                        Enter your choice:1

                                Enter the data:
                                        23

                                Input Restriction page


                        1.Insert at Front
                        2.Delete at Front
                        3.Delete at End
                        4.Display
                        5.Back to Home page
                        6.Move to Output Restricted page
                        7.Exit

                        Enter your choice:1

                                Enter the data:
                                        345

                                Input Restriction page


                        1.Insert at Front
                        2.Delete at Front
                        3.Delete at End
                        4.Display
                        5.Back to Home page
                        6.Move to Output Restricted page
                        7.Exit

                        Enter your choice:4


                        >>>>>>>>>>....Data Display....<<<<<<<<<<

                                        345

                                        23

                                Input Restriction page


                        1.Insert at Front
                        2.Delete at Front
                        3.Delete at End
                        4.Display
                        5.Back to Home page
                        6.Move to Output Restricted page
                        7.Exit

                        Enter your choice:2

                                345 is deleted successfully..!!

                                Input Restriction page


                        1.Insert at Front
                        2.Delete at Front
                        3.Delete at End
                        4.Display
                        5.Back to Home page
                        6.Move to Output Restricted page
                        7.Exit

                        Enter your choice:4


                        >>>>>>>>>>....Data Display....<<<<<<<<<<

                                        23

                                Input Restriction page


                        1.Insert at Front
                        2.Delete at Front
                        3.Delete at End
                        4.Display
                        5.Back to Home page
                        6.Move to Output Restricted page
                        7.Exit

                        Enter your choice:3

                                23 is deleted successfully..!!

                                Input Restriction page


                        1.Insert at Front
                        2.Delete at Front
                        3.Delete at End
                        4.Display
                        5.Back to Home page
                        6.Move to Output Restricted page
                        7.Exit

                        Enter your choice:4

                                !!....List Underflow....!!

                                Input Restriction page


                        1.Insert at Front
                        2.Delete at Front
                        3.Delete at End
                        4.Display
                        5.Back to Home page
                        6.Move to Output Restricted page
                        7.Exit

                        Enter your choice:5

                                Deque Menu Driven Programme


                                !..H..O..M..E..!

                        1.Input restricted
                        2.Output restricted
                        3.Exit

                        Enter your choice:1

                                Input Restriction page


                        1.Insert at Front
                        2.Delete at Front
                        3.Delete at End
                        4.Display
                        5.Back to Home page
                        6.Move to Output Restricted page
                        7.Exit

                        Enter your choice:6

                                Output Restriction page


                        1.Delete at Front
                        2.Insert at Front
                        3.Insert at End
                        4.Display
                        5.Back to Home page
                        6.Move to Input Restricted page
                        7.Exit

                        Enter your choice:4

                                !!....List Underflow....!!

                                Output Restriction page


                        1.Delete at Front
                        2.Insert at Front
                        3.Insert at End
                        4.Display
                        5.Back to Home page
                        6.Move to Input Restricted page
                        7.Exit

                        Enter your choice:1

                                !!....List Underflow....!!

                                Output Restriction page


                        1.Delete at Front
                        2.Insert at Front
                        3.Insert at End
                        4.Display
                        5.Back to Home page
                        6.Move to Input Restricted page
                        7.Exit

                        Enter your choice:324
Programme Terminates
                                Output Restriction page


                        1.Delete at Front
                        2.Insert at Front
                        3.Insert at End
                        4.Display
                        5.Back to Home page
                        6.Move to Input Restricted page
                        7.Exit

                        Enter your choice:2

                                Enter the data:
                                        342

                                Output Restriction page


                        1.Delete at Front
                        2.Insert at Front
                        3.Insert at End
                        4.Display
                        5.Back to Home page
                        6.Move to Input Restricted page
                        7.Exit

                        Enter your choice:4


                        >>>>>>>>>>....Data Display....<<<<<<<<<<

                                        342

                                Output Restriction page


                        1.Delete at Front
                        2.Insert at Front
                        3.Insert at End
                        4.Display
                        5.Back to Home page
                        6.Move to Input Restricted page
                        7.Exit

                        Enter your choice:3

                                Enter the data:325434

D:\>

*/
