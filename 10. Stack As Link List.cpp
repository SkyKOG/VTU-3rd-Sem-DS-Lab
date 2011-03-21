#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <windows.h>
#define MAX 5
struct stack
{
	int item;
	struct stack *link;
};
int count;
void push(struct stack **,int);
int pop(struct stack **,int *);
void display(struct stack **);
struct stack *getnode()
{
	struct stack *temp;
	temp=(struct stack *)malloc(sizeof(struct stack));
	return temp;
}
void main()
{
	struct stack *p;
	p=NULL;count=0;
	int ch,ele,status=0;
	while(true)
	{
		system("cls");
		printf("1. Push\n2. Pop\n3. Display\n4. Exit\n\nEnter Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:printf("Enter Element To Push : ");
			scanf("%d",&ele);
			push(&p,ele);
			break;
		case 2:ele=pop(&p,&status);
			if(status==0)
			{
				  break;
			}
			else
			{
			printf("Element Popped Is : %d",ele);
			break;
			}
		case 3:display(&p);
			break;
		case 4:exit(0);
		}
		getch();
	}
}
void push(struct stack **top,int ele)
{
	if(count==MAX)
	{
		printf("Stack Overflow");
		return;
	}
	struct stack *temp;
	temp=getnode();
	temp->item=ele;
	temp->link=*top;
	*top=temp;
	count++;
}
int pop(struct stack **top,int *status)
{
	struct stack *temp;
	int del;
	if(*top==NULL)
	{
		printf("Stack Underflow");
		*status=0;
		return NULL;
	}
	*status=1;
	temp=*top;
	del=temp->item;
	*top=(*top)->link;
	free(temp);
	count--;
	return del;	
}

void display(struct stack **top)
{
	if(*top==NULL)
	{
		printf("Stack Empty");
		return;
	}
	struct stack *temp;
	temp=*top;
	while(temp!=NULL)
	{
		printf("%d\n",temp->item);
		temp=temp->link;
	}
	printf("\n");
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