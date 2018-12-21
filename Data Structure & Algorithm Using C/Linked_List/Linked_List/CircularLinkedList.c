#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
};
struct node *start=NULL;

void *getnode()
{
	return(struct node*)malloc(sizeof(struct node));
}

void freenode(struct node *n)
{
	free(n);
}

void create()
{
	struct node *temp,*new_node,*new_temp;
	int n,i;
	printf("\n\t\tEnter Nos. of nodes:");
	scanf("%d",&n);
	printf("\n\t\tEnter the data here:\n");
	for(i=1; i<=n; i++)
	{
		if(i==1)
		{
			new_node=getnode();
			printf("\t\t");
			scanf("%d",&new_node->data);
			new_node->next=NULL;
			start=new_node;
			temp=start;
		}
		else
		{

			temp->next=getnode();
			printf("\t\t");
			temp=temp->next;
			scanf("%d",&temp->data);
			temp->next=start;
		}
	}
	
}


void display()
{
	struct node *temp,*move;
	int n,i;
	temp=start;
	if(temp==NULL)
	{
		printf("\n\t\t..........List is Empty.............\n");
	}	
	else
	{
		printf("\n\t\t......>>...Data Display...<<........\n");
		for(i=1; i<=n; i++)
		{
			
			if(i==1)
			{
				printf("\n\t\t");
				printf("%d\n",temp->data);
				temp=temp->next;
			}
			else
			{
				while(temp!=start)
				{
					printf("\n\t\t");
					printf("%d\n",temp->data);
					temp=temp->next;
				}
			}
		}
	}
}

void insert_at_beg()
{
	struct node *temp,*new_node;
	temp=start;
	if(temp==NULL)
	{
		printf("\n\t\t......>>...List is Empty...<<........");
	}
	else
	{
		new_node=getnode();
		printf("\n\t\tEnter data to insert:");
		scanf("%d",&new_node->data);
		new_node->next=temp;
		
		while(temp->next!=start)
		{
			temp=temp->next;
		}
		temp->next=new_node;
		start=new_node;
	}
}

void insert_at_end()
{
	struct node *temp,*new_node;
	int num;
	temp=start;
	
	if(start==NULL)
	{
		printf("\n\t\t.......List is Empty........!!\n");
	}
	else
	{
		new_node=getnode();
		printf("\n\t\tEnter the data here:");
		scanf("%d",&new_node->data);
		while(temp->next!=start)
		{
			temp=temp->next;
		}
		temp->next=new_node;
		temp=temp->next;
		temp->next=start;
		
	}
	
}

void insert_at_DL()
{
	struct node *temp,*new_node;
	int i,n,num;
	temp=start;
	if(temp==NULL)
	{
		printf("\n\t\t......>>...List is Empty...<<........!\n");
	}
	else
	{
		printf("\n\t\tEnter the data to insert:");
		scanf("%d",&num);
		printf("\n\t\t\tAt location:");
		scanf("%d",&n);
		for(i=1; i<n-1; i++)
		{
			temp=temp->next;
		}
		new_node=getnode();
		new_node->data=num;
		new_node->next=temp->next;
		temp->next=new_node;
	}
}

void delete_at_beg()
{
	struct node *temp,*move;
	temp=start;
	move=temp;
	if(temp==NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		while(temp->next!=start)
		{
			temp=temp->next;
		}
		temp->next=move->next;
		start=move->next;
		free(move);
	}
}
		
		
void delete_at_end()
{
	struct node *temp,*move;
	temp=start;
	if(temp==NULL)
	{
		printf("\n\t\t.....>>..List is Empty..<<.........!\n");
	}
	else
	{
		temp=temp->next;
		while(temp->next!=start)
		{
			move=temp;
			temp=temp->next;
		}
		free(temp);
		move->next=start;
		
	}
}
void delete_at_DL()
{
	struct node *temp,*move;
	int i,n,num;
	temp=start;
	if(temp==NULL)
	{
		printf("\n\t\t.....>>...List is Empty...<<........!\n");
	}
	else
	{
		printf("\n\t\tEnter the data to delete:");
		scanf("%d",&num);
		temp=temp->next;
		while(temp->data!=num)
		{
			move=temp;
			temp=temp->next;
		}
		move->next=temp->next;
		free(temp);
		
		
	}
}

void count()
{
	struct node *temp;
	int flag=1,n;
	temp=start;
	if(temp==NULL)
	{
		printf("\n\t\t.....>>..List is Empty..<<..........\n");
	}
	else
	{
		while(temp->next!=start)
		{
			temp=temp->next;
			flag++;
		}
		printf("\n\t\tTotal number of data is %d\n",flag);
	}
}

void search()
{
	struct node *temp;
	int i=1,num,flag;
	temp=start;
	if(temp==NULL)
	{
		printf("\n\t\t.....>>...List is Empty...<<.......\n");
	}
	else
	{
		printf("\n\t\tEnter data to search:");
		scanf("%d",&num);
		
		
			while(temp->data!=num)
			{
				temp=temp->next;
				i++;
				flag=1;
			}
			if(flag==1)
			{
				printf("\n\t\tData found at location %d\n",i);
			}
			else
			{
				printf("\n\t\tData is not found\n");
			}
	}
}

void copy()
{
	struct node *temp,*new_node,*clone,*head;
	temp=start;
	if(temp==NULL)
	{
		printf("\n\t\t......>>>...List is Empty...<<........!\n");
	}
	else
	{
		new_node=getnode();
		clone=new_node;
		head=clone;
		while(temp->next!=start)
		{
			clone->data=temp->data;
			clone->next=getnode();
			clone=clone->next;
			temp=temp->next;
		}
		clone->data=temp->data;
		clone->next=head;
	}
	printf("\n\t\t......>>>.....List is copied.....<<<........!\n");
	clone=head;
	while(clone->next!=head)
	{
		printf("%d\n",clone->data);
		clone=clone->next;
	}
	printf("%d\n",clone->data);
}

void reverse()
{
	struct node *temp,*new_temp,*new_node,*end;
	temp=start;
	if(temp==NULL)
	{
		printf("\n\t\t........>>.......List is Empty......<<........\n");
	}
	else
	{
		new_node=getnode();
		new_temp=new_node;
		end=new_temp;
		while(temp->next!=start)
		{
				new_node->data=temp->data;
				new_temp=getnode();
				new_temp->next=new_node;
				new_node=new_temp;
				temp=temp->next;
		}
		new_node->data=temp->data;
		new_node->data =temp->data;
		end->next=new_node;
		printf("\n\t\t!!..Data Reversed Successfully..!!\n");
		printf("\n\t\t\t\tR\tE\tV\tE\tR\tS\tE\t\t\n");
		while(new_temp->next!=end)
		{
			printf("%d\n",new_temp->data);
			new_temp=new_temp->next;
		}
		printf("%d\n",new_temp->data);
		new_temp=new_temp->next;
		printf("%d\n",new_temp->data);
		
	}
}

void concat()
{
	struct node *point1,*point2,*temp;
	printf("\n\t\tEnter the details of the fiest List\n");
	create();
	point1=start;
	printf("\n\t\tEnter the details of second List\n");
	create();
	point2=start;
	temp=point1;
	while(temp->next!=point1)
	{
		temp=temp->next;
	}
	temp->next=point2;
	temp=temp->next;
	while(temp->next!=point2)
	{  temp=temp->next ; 
	}
	temp->next=point1 ;
	temp=point1 ; 
	printf("\nThe concatenated list is \n");
	while(temp->next!=point1)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	
	printf("%d\n",temp->data);
}

void split()
{
	struct node *temp,*head,*move;
	int x,i;
	temp=start;
	if(temp==NULL)
	{
		printf("\n\t\tList is Empty\n");
	}
	else
	{
		printf("\n\t\tEnter node number from where you want to split the List:");
		scanf("%d",&x);
		for(i=1; i<=x-1; i++)
		{
			
			temp=temp->next;
		}
		move=temp;
		while(temp->next!=start)
		{
			temp=temp->next;
		}
		head=move->next;
		move->next=start;
		temp->next=head;
		printf("List one:\n");
		move=start;
		while(move->next!=start)
		{
			printf("%d\n",move->data);
			move=move->next;
		}
		printf("%d",move->data);
		printf("\nSecond list is\n");
		temp=head;
		while(temp->next!=head)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
		printf("%d\n",temp->data);
	}
}
void main()
{
	int ch;
	do
	{
		
		printf("\n\n\t\t\t\t\t***************.....LINKED LIST.....***************");
		printf("\n\n\t\t\t\t\t\t!.!..Main Menu..!.!");
		printf("\n\t\t1.Create\n\t\t2.Display\n\t\t3.Insert at beg\n\t\t4.Insert at end\n\t\t5.Insert at desire location\n\t\t6.Delete at beg\n\t\t7.Delete at end\n\t\t8.Delete at desire location\n\t\t9.Count\n\t\t10.search\n\t\t11.copy\n\t\t12.Reverse\n\t\t13.concatenate\n\t\t14.split\n\t\t15.Exit\n");
		printf("\n\t\t\t\tEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
				break;
			case 2: display();
				break;
			case 3: insert_at_beg();
				break;
			case 4: insert_at_end();
				break;
			case 5: insert_at_DL();
				break;
			case 6: delete_at_beg();
				break;
			case 7: delete_at_end();
				break;
			case 8: delete_at_DL();
				break;
			case 9: count();
				break;
			case 10: search();
				break;
			case 11: copy();
				break;
			case 12: reverse();
				break;
			case 13: concat();
				break;
			case 14: split();
				break;
			case 15: exit(0);
				break;
		}
	
	}while(ch!=15);
}





				/*
				
				
															Circular Linked List
															
															
										>>>>>>>>>>.........!!!!!......OUTPUT.......!!!!!!!<<<<<<<<<<<<
							
							
D:\P>a


                                        ***************.....LINKED LIST.....***************

                                                !.!..Main Menu..!.!
                1.Create
                2.Display
                3.Insert at beg
                4.Insert at end
                5.Insert at desire location
                6.Delete at beg
                7.Delete at end
                8.Delete at desire location
                9.Count
                10.search
                11.copy
                12.Reverse
                13.concatenate
                14.split
                15.Exit

                                Enter your choice:1

                Enter Nos. of nodes:6

                Enter the data here:
                22
                33
                44
                55
                66
                77


                                        ***************.....LINKED LIST.....***************

                                                !.!..Main Menu..!.!
                1.Create
                2.Display
                3.Insert at beg
                4.Insert at end
                5.Insert at desire location
                6.Delete at beg
                7.Delete at end
                8.Delete at desire location
                9.Count
                10.search
                11.copy
                12.Reverse
                13.concatenate
                14.split
                15.Exit

                                Enter your choice:2

                ......>>...Data Display...<<........

                22

                33

                44

                55

                66

                77


                                        ***************.....LINKED LIST.....***************

                                                !.!..Main Menu..!.!
                1.Create
                2.Display
                3.Insert at beg
                4.Insert at end
                5.Insert at desire location
                6.Delete at beg
                7.Delete at end
                8.Delete at desire location
                9.Count
                10.search
                11.copy
                12.Reverse
                13.concatenate
                14.split
                15.Exit

                                Enter your choice:3

                Enter data to insert:11


                                        ***************.....LINKED LIST.....***************

                                                !.!..Main Menu..!.!
                1.Create
                2.Display
                3.Insert at beg
                4.Insert at end
                5.Insert at desire location
                6.Delete at beg
                7.Delete at end
                8.Delete at desire location
                9.Count
                10.search
                11.copy
                12.Reverse
                13.concatenate
                14.split
                15.Exit

                                Enter your choice:2

                ......>>...Data Display...<<........

                11

                22

                33

                44

                55

                66

                77


                                        ***************.....LINKED LIST.....***************

                                                !.!..Main Menu..!.!
                1.Create
                2.Display
                3.Insert at beg
                4.Insert at end
                5.Insert at desire location
                6.Delete at beg
                7.Delete at end
                8.Delete at desire location
                9.Count
                10.search
                11.copy
                12.Reverse
                13.concatenate
                14.split
                15.Exit

                                Enter your choice:4

                Enter the data here:888


                                        ***************.....LINKED LIST.....***************

                                                !.!..Main Menu..!.!
                1.Create
                2.Display
                3.Insert at beg
                4.Insert at end
                5.Insert at desire location
                6.Delete at beg
                7.Delete at end
                8.Delete at desire location
                9.Count
                10.search
                11.copy
                12.Reverse
                13.concatenate
                14.split
                15.Exit

                                Enter your choice:2

                ......>>...Data Display...<<........

                11

                22

                33

                44

                55

                66

                77

                888


                                        ***************.....LINKED LIST.....***************

                                                !.!..Main Menu..!.!
                1.Create
                2.Display
                3.Insert at beg
                4.Insert at end
                5.Insert at desire location
                6.Delete at beg
                7.Delete at end
                8.Delete at desire location
                9.Count
                10.search
                11.copy
                12.Reverse
                13.concatenate
                14.split
                15.Exit

                                Enter your choice:5

                Enter the data to insert:40

                        At location:4


                                        ***************.....LINKED LIST.....***************

                                                !.!..Main Menu..!.!
                1.Create
                2.Display
                3.Insert at beg
                4.Insert at end
                5.Insert at desire location
                6.Delete at beg
                7.Delete at end
                8.Delete at desire location
                9.Count
                10.search
                11.copy
                12.Reverse
                13.concatenate
                14.split
                15.Exit

                                Enter your choice:2

                ......>>...Data Display...<<........

                11

                22

                33

                40

                44

                55

                66

                77

                888


                                        ***************.....LINKED LIST.....***************

                                                !.!..Main Menu..!.!
                1.Create
                2.Display
                3.Insert at beg
                4.Insert at end
                5.Insert at desire location
                6.Delete at beg
                7.Delete at end
                8.Delete at desire location
                9.Count
                10.search
                11.copy
                12.Reverse
                13.concatenate
                14.split
                15.Exit

                                Enter your choice:6


                                        ***************.....LINKED LIST.....***************

                                                !.!..Main Menu..!.!
                1.Create
                2.Display
                3.Insert at beg
                4.Insert at end
                5.Insert at desire location
                6.Delete at beg
                7.Delete at end
                8.Delete at desire location
                9.Count
                10.search
                11.copy
                12.Reverse
                13.concatenate
                14.split
                15.Exit

                                Enter your choice:2

                ......>>...Data Display...<<........

                22

                33

                40

                44

                55

                66

                77

                888


                                        ***************.....LINKED LIST.....***************

                                                !.!..Main Menu..!.!
                1.Create
                2.Display
                3.Insert at beg
                4.Insert at end
                5.Insert at desire location
                6.Delete at beg
                7.Delete at end
                8.Delete at desire location
                9.Count
                10.search
                11.copy
                12.Reverse
                13.concatenate
                14.split
                15.Exit

                                Enter your choice:7


                                        ***************.....LINKED LIST.....***************

                                                !.!..Main Menu..!.!
                1.Create
                2.Display
                3.Insert at beg
                4.Insert at end
                5.Insert at desire location
                6.Delete at beg
                7.Delete at end
                8.Delete at desire location
                9.Count
                10.search
                11.copy
                12.Reverse
                13.concatenate
                14.split
                15.Exit

                                Enter your choice:2

                ......>>...Data Display...<<........

                22

                33

                40

                44

                55

                66

                77


                                        ***************.....LINKED LIST.....***************

                                                !.!..Main Menu..!.!
                1.Create
                2.Display
                3.Insert at beg
                4.Insert at end
                5.Insert at desire location
                6.Delete at beg
                7.Delete at end
                8.Delete at desire location
                9.Count
                10.search
                11.copy
                12.Reverse
                13.concatenate
                14.split
                15.Exit

                                Enter your choice:8

                Enter the data to delete:66


                                        ***************.....LINKED LIST.....***************

                                                !.!..Main Menu..!.!
                1.Create
                2.Display
                3.Insert at beg
                4.Insert at end
                5.Insert at desire location
                6.Delete at beg
                7.Delete at end
                8.Delete at desire location
                9.Count
                10.search
                11.copy
                12.Reverse
                13.concatenate
                14.split
                15.Exit

                                Enter your choice:2

                ......>>...Data Display...<<........

                22

                33

                40

                44

                55

                77


                                        ***************.....LINKED LIST.....***************

                                                !.!..Main Menu..!.!
                1.Create
                2.Display
                3.Insert at beg
                4.Insert at end
                5.Insert at desire location
                6.Delete at beg
                7.Delete at end
                8.Delete at desire location
                9.Count
                10.search
                11.copy
                12.Reverse
                13.concatenate
                14.split
                15.Exit

                                Enter your choice:9

                Total number of data is 6


                                        ***************.....LINKED LIST.....***************

                                                !.!..Main Menu..!.!
                1.Create
                2.Display
                3.Insert at beg
                4.Insert at end
                5.Insert at desire location
                6.Delete at beg
                7.Delete at end
                8.Delete at desire location
                9.Count
                10.search
                11.copy
                12.Reverse
                13.concatenate
                14.split
                15.Exit

                                Enter your choice:10

                Enter data to search:55

                Data found at location 5


                                        ***************.....LINKED LIST.....***************

                                                !.!..Main Menu..!.!
                1.Create
                2.Display
                3.Insert at beg
                4.Insert at end
                5.Insert at desire location
                6.Delete at beg
                7.Delete at end
                8.Delete at desire location
                9.Count
                10.search
                11.copy
                12.Reverse
                13.concatenate
                14.split
                15.Exit

                                Enter your choice:11

                ......>>>.....List is copied.....<<<........!
22
33
40
44
55
77


                                        ***************.....LINKED LIST.....***************

                                                !.!..Main Menu..!.!
                1.Create
                2.Display
                3.Insert at beg
                4.Insert at end
                5.Insert at desire location
                6.Delete at beg
                7.Delete at end
                8.Delete at desire location
                9.Count
                10.search
                11.copy
                12.Reverse
                13.concatenate
                14.split
                15.Exit

                                Enter your choice:12

                !!..Data Reversed Successfully..!!

                                R       E       V       E       R       S       E
77
55
44
40
33
22


                                        ***************.....LINKED LIST.....***************

                                                !.!..Main Menu..!.!
                1.Create
                2.Display
                3.Insert at beg
                4.Insert at end
                5.Insert at desire location
                6.Delete at beg
                7.Delete at end
                8.Delete at desire location
                9.Count
                10.search
                11.copy
                12.Reverse
                13.concatenate
                14.split
                15.Exit

                                Enter your choice:14

                Enter node number from where you want to split the List:33
List one:
22
33
40
Second list is
44
55
77


                                        ***************.....LINKED LIST.....***************

                                                !.!..Main Menu..!.!
                1.Create
                2.Display
                3.Insert at beg
                4.Insert at end
                5.Insert at desire location
                6.Delete at beg
                7.Delete at end
                8.Delete at desire location
                9.Count
                10.search
                11.copy
                12.Reverse
                13.concatenate
                14.split
                15.Exit

                                Enter your choice:13

                Enter the details of the fiest List

                Enter Nos. of nodes:4

                Enter the data here:
                22
                33
                44
                55

                Enter the details of second List

                Enter Nos. of nodes:3

                Enter the data here:
                66
                77
                88

The concatenated list is
22
33
44
55
66
77
88


                                        ***************.....LINKED LIST.....***************

                                                !.!..Main Menu..!.!
                1.Create
                2.Display
                3.Insert at beg
                4.Insert at end
                5.Insert at desire location
                6.Delete at beg
                7.Delete at end
                8.Delete at desire location
                9.Count
                10.search
                11.copy
                12.Reverse
                13.concatenate
                14.split
                15.Exit

                                Enter your choice:15

D:\P>

*/
