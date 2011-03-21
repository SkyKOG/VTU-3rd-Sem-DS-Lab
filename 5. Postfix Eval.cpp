#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <process.h>

int stack[20];
int top;

void push(int);
int pop();
void eval(char post[20]);

void main()
{
	char post[20];
	top=-1;
	printf("Enter Postfix Expression : ");
	gets(post);
	eval(post);
	printf("The Evaluated Anwer Is : %d",pop());
	getch();
}
void push(int ele)
{
	stack[++top]=ele;
}

int pop()
{
	return (stack[top--]);
}

void eval(char post[20])
{
	char ch;
	int i,b,a;
	for(i=0;post[i];i++)
	{
		ch=post[i];
		if(isdigit(ch))
			push(ch-'0');
		else
		{  
			b=pop();
			a=pop();
			switch(ch)
			{
			case '+':push(a+b);
				break;
			case '-':push(a-b);
				break;
			case '*':push(a*b);
				break;
			case '/':if(b==0)
					 {
						 printf("Devide By Zero");
						 getch();
						 exit(0);
					 }
					 push(a/b);
			default:printf("Invalid Operation");
			}
		}
	}
}



/*
License
=======
    Copyright (C) 2011 SkyKOG

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

	
