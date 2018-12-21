#include<stdio.h>
#define Max 10
void exit();
int stack[20];
int top=-1,data;
void stack_insert()
{
	if(top==Max-1)
	{
		printf("\n\t\t\t\t!!....Stack Overflow....!!\n");
	}
	else
	{
		if(top==-1)
		{
			top=top+1;
			printf("\n\t\t\t\tEnter data:");
			scanf("%d",&stack[top]);
		}
		else
		{
			top=top+1;
		printf("\n\t\t\t\tEnter Data:");
		scanf("%d",&stack[top]);
		}
		data=stack[top];
		printf("\n\t\t\t\t%d Data inserted successfully\n",data);
		
	}
}

void stack_delete()
{
	if(top==-1)
	{
		printf("\n\t\t\t\t!!....stack Underflow....!!\n");
	}
	else
	{
		data=stack[top];
			top=top-1;
			printf("\n\t\t\t\t%d is deleted successfully\n");
	}
}

void stack_display()
{
	int i;
	if(top==-1)
	{
		printf("\n\t\t\t\t!!....stack Overflow....!!\n");
	}
	else
	{
		printf("\n\t\t\t\t>>>>....Data Display....<<<<\n");
		printf("\n");
			for(i=top; i>=0; i--)
		{
			printf("\t\t");
			printf("%d",stack[i]);
		}
	
	}
}

void main()
{
	int choice;
	do
	{
		printf("\n\n\t\t\t\t\tStack \tArray \tMenu \tDriven \tProgramme\n\n");
		printf("\n\t\t\t1.push\n\t\t\t2.pop\n\t\t\t3.Display\n\t\t\t4.Exit\n");
		printf("\n\t\t\tEnter your choice:");
		scanf("\t\t\t%d",&choice);
		switch(choice)
		{
			case 1:stack_insert();
			break;
			case 2:stack_delete();
			break;
			case 3:stack_display();
			break;
			case 4: exit();
			default : printf("\n\t\t\t\t\tWRONG CHOICE");
		}
	}while(choice!=4);
}


/*
						>>>>>>>>>>.....OUTPUT.....<<<<<<<<<<
C:\Users\Sonu Shahuji>d:
						
						
D:\>gcc stack_array.c

D:\>a


                                        Stack   Array   Menu    Driven  Programme


                        1.push
                        2.pop
                        3.Display
                        4.Exit

                        Enter your choice:1

                                Enter data:34

                                34 Data inserted successfully


                                        Stack   Array   Menu    Driven  Programme


                        1.push
                        2.pop
                        3.Display
                        4.Exit

                        Enter your choice:3

                                >>>>....Data Display....<<<<

                34

                                        Stack   Array   Menu    Driven  Programme


                        1.push
                        2.pop
                        3.Display
                        4.Exit

                        Enter your choice:1

                                Enter Data:35

                                35 Data inserted successfully


                                        Stack   Array   Menu    Driven  Programme


                        1.push
                        2.pop
                        3.Display
                        4.Exit

                        Enter your choice:3

                                >>>>....Data Display....<<<<

                35              34

                                        Stack   Array   Menu    Driven  Programme


                        1.push
                        2.pop
                        3.Display
                        4.Exit

                        Enter your choice:1

                                Enter Data:36

                                36 Data inserted successfully


                                        Stack   Array   Menu    Driven  Programme


                        1.push
                        2.pop
                        3.Display
                        4.Exit

                        Enter your choice:3

                                >>>>....Data Display....<<<<

                36              35              34

                                        Stack   Array   Menu    Driven  Programme


                        1.push
                        2.pop
                        3.Display
                        4.Exit

                        Enter your choice:137

                                        WRONG CHOICE

                                        Stack   Array   Menu    Driven  Programme


                        1.push
                        2.pop
                        3.Display
                        4.Exit

                        Enter your choice:3

                                >>>>....Data Display....<<<<

                36              35              34

                                        Stack   Array   Menu    Driven  Programme


                        1.push
                        2.pop
                        3.Display
                        4.Exit

                        Enter your choice:1

                                Enter Data:37

                                37 Data inserted successfully


                                        Stack   Array   Menu    Driven  Programme


                        1.push
                        2.pop
                        3.Display
                        4.Exit

                        Enter your choice:3

                                >>>>....Data Display....<<<<

                37              36              35              34

                                        Stack   Array   Menu    Driven  Programme


                        1.push
                        2.pop
                        3.Display
                        4.Exit

                        Enter your choice:2

                                37 is deleted successfully


                                        Stack   Array   Menu    Driven  Programme


                        1.push
                        2.pop
                        3.Display
                        4.Exit

                        Enter your choice:3

                                >>>>....Data Display....<<<<

                36              35              34

                                        Stack   Array   Menu    Driven  Programme


                        1.push
                        2.pop
                        3.Display
                        4.Exit

                        Enter your choice:2

                                36 is deleted successfully


                                        Stack   Array   Menu    Driven  Programme


                        1.push
                        2.pop
                        3.Display
                        4.Exit

                        Enter your choice:3

                                >>>>....Data Display....<<<<

                35              34

                                        Stack   Array   Menu    Driven  Programme


                        1.push
                        2.pop
                        3.Display
                        4.Exit

                        Enter your choice:2

                                35 is deleted successfully


                                        Stack   Array   Menu    Driven  Programme


                        1.push
                        2.pop
                        3.Display
                        4.Exit

                        Enter your choice:3

                                >>>>....Data Display....<<<<

                34

                                        Stack   Array   Menu    Driven  Programme


                        1.push
                        2.pop
                        3.Display
                        4.Exit

                        Enter your choice:2

                                34 is deleted successfully


                                        Stack   Array   Menu    Driven  Programme


                        1.push
                        2.pop
                        3.Display
                        4.Exit

                        Enter your choice:3

                                !!....stack Overflow....!!


                                        Stack   Array   Menu    Driven  Programme


                        1.push
                        2.pop
                        3.Display
                        4.Exit

                        Enter your choice:4

D:\>

*/