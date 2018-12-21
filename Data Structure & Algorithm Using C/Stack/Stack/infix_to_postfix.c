#include<stdio.h>
#include<string.h>
#include<ctype.h>
char stack[20];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

int main()
{
	int ch;
	do
	{
			char exp[20];
			char *e, x;
			printf("Enter the expression :: ");
			scanf("%s",exp);
			e = exp;
			while(*e != '\0')
		{
				if(isalnum(*e))
				printf("%c",*e);
				else if(*e == '(')
				push(*e);
				else if(*e == ')')
			{
				while((x = pop()) != '(')
                printf("%c", x);
			}
			else
			{
				while(priority(stack[top]) >= priority(*e))
                printf("%c",pop());
				push(*e);
			}
			e++;
		}
				while(top != -1)
			{
				printf("%c",pop());
			}
			printf("Would you like to continue?\nPress 1.YES\n2.NO\n");
			scanf("%d",&ch);
	}while(ch!=1);
}