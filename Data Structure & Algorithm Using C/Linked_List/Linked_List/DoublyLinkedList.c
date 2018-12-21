#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *start=NULL;

//getnode function
void *getnode()
{
	return(struct node*)malloc(sizeof(struct node));
}

//freenode function
void freenode(struct node *n)
{
	free(n);
}

//create function
void create()
{
	struct node *temp,*new_node;
	int i,n;
	printf("Enter Nos. of nodes:");
	scanf("%d",&n);
	printf("Enter the data here:\n");
	for(i=0; i<n; i++)
	{
		if(i==0)
		{
			new_node=getnode();
			new_node->prev=NULL;
			scanf("%d",&new_node->data);
			new_node->next=NULL;
			start=new_node;
			temp=start;
		}
		else
		{
			
			temp->next=getnode();
			(temp->next)->prev=temp;
			temp=temp->next;
			scanf("%d",&temp->data);
			temp->next=NULL;
		}
		
	}
	
}

//display function
void display()
{
	struct node *temp;
	temp=start;
	if(temp==NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}

//insert at beg
void insert_at_beg()
{
	struct node *temp,*new_node;
	int num;
	temp=start;
	if(temp==NULL)
	{
	printf("List is Empty\n");
	}
	else
	{
		printf("Enter data to insert:");
		scanf("%d",&num);
		new_node=getnode();
		new_node->prev=NULL;
		new_node->next=temp;
		temp->prev=new_node;
		new_node->data=num;
		start=new_node;
		temp=start;
	}
}
void insert_at_end()
{
	struct node *temp,*new_node;
	int num;
	temp=start;
	if(temp==NULL)
	{
		printf("List is Empty");
	}
	else
	{
		printf("Enter data to insert:");
		scanf("%d",&num);
		new_node=getnode();
		new_node->data=num;
		new_node->next=NULL;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new_node;
		new_node->prev=temp;
	}
}

void insert_at_DL()
{
	struct node *temp,*new_node;
	int i,n,num;
	temp=start;
	if(temp==NULL)
	{
		printf("List is Empty");
	}
	else
	{
		printf("Enter the data to Insert:");
		scanf("%d",&num);
		printf("Enter the location where you want to Insert the data:");
		scanf("%d",&n);
		n--;
		new_node=getnode();
		new_node->data=num;
		for(i=1; i<(n-2); i++)
		{
			temp=temp->next;
		}
		new_node->next=temp->next;
		(temp->next)->prev=new_node;
		
		
	}
}
void delete_at_beg()
{
	struct node *temp,*new_node;
	int n,num;
	temp=start;
	if(temp==NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		start=start->next;
		(temp->next)->prev=NULL;
		free(temp);
	}
}
void delete_at_end()
{
	struct node *move,*temp;
	move=start;
	if(move==NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		while(move->next!=NULL)
		{
			temp=move;
			move=move->next;
		}
		(temp->next)->prev=NULL;
		temp->next=NULL;
		free(move);
	}
}

void delete_at_DL()
{
	struct node *temp,*move,*new_temp;
	int n,num,i;
	move=start;
	if(move==NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		printf("Enter the data to delete:");
		scanf("%d",&num);
		printf("Enter the location from where you want to delete:");
		scanf("%d",&n);
		for(i=1; i<=(n-1); i++)
		{
			move=move->next;
		}
		(move->prev)->next=move->next;
		(move->next)->prev=move->prev;
		free(move);
	}
}	

void count ()
{ 
	struct node *temp;
	int count =0;
	temp = start ;
	while (temp!=NULL)
	{ 
		count++;
		temp=temp->next;
	}

printf("Total no of data in the list is %d\t" ,count ) ;
}

void copy ()
{ 
	struct node *temp,*p ,*new_node,*new_temp;
	temp = start ;
	printf("\n Before copying\n" ) ;
	display();
	new_node=getnode();
	new_temp=new_node;
	new_temp->prev=NULL ;

	while (temp->next!=NULL)
	{
		new_node->data=temp->data ;
		new_node->next=getnode();
		new_node->next->prev =new_node;
		new_node=new_node->next  ;
		temp=temp->next ;
	}

	new_node->data =temp->data;
	new_node->next=NULL;
	printf("\nList has been copied " ) ;
	start =new_temp;
	display();
}


void reverse()
{ 
	struct node *temp ;
	temp = start ;
	while ( temp->next!=NULL )
	{ 
		temp = temp->next ;
	}

	printf("\nReversed list is\n" ) ;
	while ( temp!=NULL )
	{ 
		printf("%d\t" ,temp->data ) ;
		temp = temp->prev ;
	}
}


void concat()
{ 
	struct node * s1 , *s2 , *temp ;
	printf("\nEnter details of the list 1\t" ) ;
	create(); s1= start ;
	printf("\nEnter details of the list 2\t" ) ;
	create(); s2=start ;

	temp=s1 ;
	while ( temp->next!=NULL )
	{ 
		temp=temp->next ;
	}
	temp->next = s2 ;
	s2->prev = temp ;
	printf("\nThe concatenated list is \n" ) ;
	start = s1 ;
	display();
}

void split()
{ 

	struct node * temp , *s1 , *s2 ;
	int pos,i ;
	temp =start ;
	printf("\nEnter the postion at which you want to separate the lists\n" ) ;
	scanf("%d" ,&pos ) ;
	for (i=1 ; i<=pos- 1 ; i++ )
	{
			temp=temp->next  ;
	}
 
	s2 = temp->next ;
	s2->prev = NULL ;

	temp->next = NULL ;
	printf("\nFirst list is \n" ) ;
	display();
	printf("\nSecond list is \n" ) ;
	start = s2 ;
	display();
}

void search()
{ //function to search any specific element in the list
struct node * temp ;
int ele , c=0, k=1 ;
temp =start ;
printf("\nEnter the element you want to search in the list\t") ;
scanf("%d" ,&ele ) ;
while ( temp!=NULL )
{ if ( ele == temp->data ) { printf("\nElement found at node %d\t" ,k) ; c++ ; }
temp=temp->next ;
k++ ;
}
if ( c==0 ) printf("\nElement not found\n" ) ;
else printf("\nElement found %d time(s)\n",c ) ;
}

void main()
{
	int n;
	do
	{
	printf("\n\n\t\t\t\t\t***************.....LINKED LIST.....***************");
	printf("\n\n\t\t\t\t\t\t!.!..Main Menu..!.!");
	printf("\n\t\t1.Create\n\t\t2.Dispaly\n\t\t3.Insert at beg\n\t\t4.Insert at end\n\t\t5.Insert at desire location\n\t\t6.Delete at beg\n\t\t7.Delete at end\n\t\t8.Delete at desire loction\n\t\t9.Search data\n\t\t10.count\n\t\t11.Split\n\t\t12.copy\n\t\t13.concatenate\n\t\t14.Reverse\n\t\t15.Exit");
	printf("\n\t\t\t\t\t  Enter your choice here:");
	scanf("%d",&n);
	switch(n)
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
		case 9: search();
			break;
		case 10:count();
			break;
		case 11:split();
				break;
		case 12:copy();
				break;
		case 13:concat();
				break;
		case 14:reverse();
				break;
		case 15: exit(0);
				break;
	//	default : printf("Sorry,invalid choice:..!");
	//		break;
	}
	}while(n!=15);

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
