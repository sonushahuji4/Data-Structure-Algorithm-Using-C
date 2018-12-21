
#include<stdio.h>

#define Max 10
int Q[20];
int front=-1,rear=-1,data;

void exit();

void insert_Q()
{
	if(front==0 && rear==Max-1)
	{
		printf("\n\t\t\t!......Q_Overflow......!\n");
	}
	else if(front!=0 && rear==Max-1)
	{
		rear=0;
		printf("\n\t\t\tEnter data:");
		scanf("%d",&Q[rear]);
		rear=rear+1;
		if(rear==front-1)
		{
			printf("\n\t\t\t!......Q_Underflow......!\n");
		}
		
	}
	else //if(rear!=Max-1)
	{
		if(front==-1 && rear==-1)
		{
			front=0;
			rear=0;
		}
		else
		{
		rear=rear+1;
		}
		printf("\n\t\t\tEnter data:");
		scanf("%d",&data);
		Q[rear]=data;

	}
}

void delete_Q()
{
	if(front==-1 && rear==-1)
	{
		printf("\n\t\t\t!......Q_Underflow......!\n");
	}
	else if(front==rear)
	{
		data=Q[front];
		front=-1;
		rear=-1;
		printf("\n\t\t\t\t%d is deleted successfully\n",data);
	}
	else
	{
		if(front==Max-1)
		{
			data=Q[front];
			printf("\n\t\t\t\t%d is deleted successfully\n",data);
			front=0;
		}
		else
		{
			data=Q[front];
			front=front+1;
			printf("\n\t\t\t\t%d is deleted successfully\n",data);
		}
	}
}


void Q_Display()
{
	int temp;
	if(front==-1 && rear==-1)
	{
		printf("\n\t\t\t\t\t\t!!......Q_Underflow......!!\n");
	}
	else
	{
		temp=front;
		printf("\n\t\t\t\t\t\t>>>>>..Data Display..<<<<<<\n");
		printf("\n");
		while(temp!=rear)
		{
			printf("\n\t\t\t");
			printf("%d",Q[temp]);
			temp=temp+1;
		}
		printf("\n\t\t\t");
		printf("%d",Q[temp]);
	}
}

void main()
{
	int ch;
	do
	{
		printf("\n\t\t\t\t\t______Circular Queue Array Menu Driven Programme______\n");
		printf("\n\n\t\t\t\t\t\tH\tO\tM\tE\n");
		printf("\t\t1.EN_Q\n\t\t2.DE_Q\n\t\t3.Display_Q\n\t\t4.Exit\n");
		printf("\n\t\t\tEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert_Q();
				break;
			case 2: delete_Q();
				break;
			case 3: Q_Display();
				break;
			case 4: exit(0);
			default: printf("\n\t\t\t!!!!.......Wrong choice.....!!!!....\n");
				  printf("\n\t\t******* _____Programme_____*******\n");                    
		}
	}while(ch!=4);
}
