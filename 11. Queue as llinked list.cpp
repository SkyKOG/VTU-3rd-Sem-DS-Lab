#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <process.h>

#define MAX 5

int count=0;
struct queue 
{
	int item;
	struct queue *link;
};

void insert(struct queue **,int);
void del(struct queue **);
void display(struct queue **);

void main()
{
	struct queue *p;
	p=NULL;
	int ch,ele;
	while(true)
	{
		system("cls");
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\nEnter Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:printf("Enter Element To Insert : ");
			scanf("%d",&ele);
			insert(&p,ele);
			break;
		case 2:del(&p);
			break;
		case 3:display(&p);
			break;
		case 4:exit(0);
			break;
		default:printf("Invalid Choice");
			break;
		}
		getch();
	}
}

void insert(struct queue **q,int ele)
{
	if(count==MAX)
	{
		printf("Queue Overflow");
		return;
	}
	struct queue *temp;
	temp=(struct queue *)malloc(sizeof(struct queue));
	temp->item=ele;
	if(*q==NULL)
	{
		temp->link=NULL;
		*q=temp;
		count++;
		return;
	}
	temp->link=(*q);
	(*q)=temp;
	count++;
}

void del(struct queue **q)
{
	if(count==0)
	{
		printf("Queue Underflow");
		return;
	}
	struct queue *temp;
	temp=*q;
	if(temp->link==NULL)
	{
		printf("Element Deleted : %d",temp->item);
		*q=NULL;
		free(temp);count--;
		return;
	}
	struct queue *cur,*prev;
	prev=NULL;
	cur=*q;
	while(cur->link!=NULL)
	{
		prev=cur;
		cur=cur->link;
	}
	printf("Item Deleted : %d",cur->item);
	prev->link=NULL;
	free(cur);count--;
	return;
}

void display(struct queue **q)
{
	struct queue *temp;
	temp=*q;
	if(temp==NULL)
	{
		printf("Empty Queue");
		return;
	}
	while(temp!=NULL)
	{
		printf("%d ",temp->item);
		temp=temp->link;
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
