#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <windows.h>

#define MAX 5
struct stack
{
	int arr[MAX];
	int top;
};

void push(struct stack *,int);
int pop(struct stack *,int *);
void display(struct stack *);

void main()
{
	struct stack s;
	s.top=-1;
	int ch,status=0,ele;
	while(1)
	{
		system("cls");
		printf("1. Push\n2. Pop\n3. Display\n4. Exit\n\nEnter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: printf("Enter Element To Push : ");
			scanf("%d",&ele);
			push(&s,ele);
			break;
		case 2: ele=pop(&s,&status);
			if(status)
				printf("The Popped Element Is : %d",ele);
			else
				printf("Stack Underflow");
			break;
		case 3: display(&s);
			break;
		case 4: exit(0);
		default : printf("Invalid Selection");
		}
		getch();
	}
}

void push(struct stack *s,int ele)
{
	if(s->top==MAX-1)
	{
		printf("Stack Overflow");
		return;
	}
	s->top++;

	s->arr[s->top]=ele;
}

int pop(struct stack *s,int *status)
{
	int item;
	if(s->top==-1)
	{
		*status=0;
		return NULL;
	}
	*status=1;
	item=s->arr[s->top];
	s->top--;
	return item;
}
void display(struct stack *s)
{
	if(s->top==-1)
	{
		printf("Stack Is Empty");
		return;
	}

	int i;
	for(i=s->top;i>=0;i--)
	{
		printf("%d\n",s->arr[i]);
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

