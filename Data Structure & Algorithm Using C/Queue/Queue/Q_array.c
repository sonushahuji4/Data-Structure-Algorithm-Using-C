#include<stdio.h>
void exit();

#define Max 10
int Q[Max];
int front=-1,rear=-1,data,temp;

void EN_Q()
{
	if(rear==Max-1)
	{
		printf("\n\t\t\t!......Q_Overflow......!\n");
	}
	else
	{
		if(front==-1 && rear==-1)
		
		{
			front=front+1;
			rear=rear+1;
		}
		else
		rear=rear+1;
               // printf("rear=%d",rear);
		printf("\n\t\t\tEnter the data:");
		scanf("%d",&Q[rear]);
		
	}
}

void DE_Q()
{
	if(front==-1 && rear==-1)
	{
		printf("\n\t\t\t\t\t\t!!......Q_Underflow......!!");
	}
	else
	{
		data=Q[front];
		if(front==rear)
		{
		front=-1;
		rear=-1;
		printf("\n\t\t\t\t\t\t%d is deleted successfully\n",data);
		}
		else
		{
			front=front+1;
			printf("\n\t\t\t\t\t\t%d is deleted successfully\n",data);
		}
	}
}

void Q_Display()
{
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
			//printf("\t\t\t");
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
		printf("\n\t\t\t\t\t______Queue Array Menu Driven Programme______\n");
		printf("\n\n\t\t\t\t\t\tH\tO\tM\tE\n");
		printf("\t\t1.EN_Q\n\t\t2.DE_Q\n\t\t3.Display_Q\n\t\t4.Exit\n");
		printf("\n\t\t\tEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: EN_Q();
				break;
			case 2: DE_Q();
				break;
			case 3: Q_Display();
				break;
			case 4: exit(0);
			default: printf("\n\t\t\t!!!!.......Wrong choice.....!!!!....\n");
				  printf("\n\t\t******* _____Programme_____*******\n");                    
		}
	}while(ch!=4);
}
