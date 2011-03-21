#include <stdio.h>
#include <conio.h>'

int stack[10];
int top=-1;

void push(char);
char pop();
int stpri(char ch);
int inpri(char ch);
void convert(char [],char[]);

void main()
{
	char infix[20],postfix[20];
	push('#');
	printf("Enter Infix Expression : ");
	fflush(stdin);
	gets(infix);
	convert(infix,postfix);
	printf("The Evaluated Postfix is : %s",postfix);
	getch();
}

void push(char ch)
{
	stack[++top]=ch;
}

char pop()
{
	return (stack[top--]);
}

int stpri(char ch)
{
	switch(ch)
	{
	case '#':
	case '(':return 0;
	case '+':
	case '-':return 2;
	case '*':
	case '/':return 4;
	case '$':return 5;
	}
}

int inpri(char ch)
{
	switch(ch)
	{
	case '+':
	case '-':return 1;
	case '*':
	case '/':return 3;
	case '$':return 6;
	}
}

void convert(char inf[20],char post[20])
{
	int i,j=0;
	char ch;
	for(i=0;inf[i];i++)
	{
		ch=inf[i];
		switch(ch)
		{
		case '(':push(ch);
			break;
		case ')':while(stack[top]!='(')
					 post[j++]=pop();
				pop();
				break;
		case '+':
		case '-':
		case '/':
		case '*':
		case '$':while(stpri(stack[top])>inpri(ch))
					 post[j++]=pop();
			push(ch);
			break;
		default:post[j++]=ch;
		}
	}
	while(stack[top]!='#')
		post[j++]=pop();
	post[j]='\0';
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

