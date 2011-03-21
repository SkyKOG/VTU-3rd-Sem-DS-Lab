#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <windows.h>
#define MAX 5
struct queue
{
	int arr[MAX];
	int f,r,count;
};
void insq(struct queue *,int);
void delq(struct queue *);
void display(struct queue *);

void main()
{
	int ele,ch;
	struct queue q;
	q.f=q.r=q.count=0;
	while(true)
	{
		system("cls");
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\nEnter Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:printf("Enter Element To Insert : ");
			scanf("%d",&ele);
			insq(&q,ele);
			break;
		case 2:delq(&q);
			break;
		case 3:display(&q);
			break;
		case 4:exit(0);
			break;
		default:printf("Invalid Selection");
		}
		getch();
	}
}
void insq(struct queue *q,int ele)
{
	if(q->count==MAX)
	{
		printf("Queue Full");
		return;
	}
	q->arr[q->r]=ele;
	q->r=(q->r+1)%MAX;
	q->count++;
}
void delq(struct queue *q)
{
	if(q->count==0)
	{
		printf("Queue Empty");
		return;
	}
	printf("Element Deleted : %d",q->arr[q->f]);
	q->f=(q->f+1)%MAX;
	q->count--;
}
void display(struct queue *q)
{
	int i,t;
	if(q->count==0)
	{
		printf("Empty Queue");
		return;
	}
	t=q->f;
	for(i=0;i<q->count;i++)
	{
		printf("%d ",q->arr[t]);
		t=(t+1)%MAX;
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