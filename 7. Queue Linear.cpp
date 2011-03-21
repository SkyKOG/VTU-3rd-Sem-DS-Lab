#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <process.h>
#define MAX 5

struct queue
{
	int arr[MAX];
	int f,r;
};
void insq(struct queue *,int);
void delq(struct queue *);
void display(struct queue *);

void main()
{
	int ch,ele;
	struct queue q;
	q.f=-1;
	q.r=0;
	while(true)
	{
		system("cls");
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n Enter Choice : ");
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
	if(q->r==MAX)
	{
		printf("Queue Full");
		return;
	}
	q->arr[q->r]=ele;
	q->r++;
	if(q->f==-1)
		q->f=0;
}
void delq(struct queue *q)
{
	if(q->f==-1)
	{
		printf("Queue Empty");
		return;
	}
	printf("Element Deleted is : %d",q->arr[q->f]);
	q->f++;
	if(q->f==q->r)
	{
		q->f=-1;
		q->r=0;
	}
}
void display(struct queue *q)
{
	int i;
	if(q->f==-1)
	{
		printf("Empty Queue");
		return;
	}
	for(i=q->f;i<q->r;i++)
	{
		printf("%d ",q->arr[i]);
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

