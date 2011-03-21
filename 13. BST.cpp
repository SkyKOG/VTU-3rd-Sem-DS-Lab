#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <process.h>

struct node
{
	struct node *l;
	struct node *r;
	int data;
};
void insert(struct node **,int);
void inorder(struct node *);
void postorder(struct node *);
void preorder(struct node *);
void display(struct node *,int);

void main()
{
	int ch,ele,lvl=1;
	struct node *p;
	p=NULL;
	while(true)
	{
		system("cls");
		printf("1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Display\n6. Exit\n\nEnter Selection : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:printf("Enter Element To Insert : ");
			scanf("%d",&ele);
			insert(&p,ele);
			break;
		case 2:preorder(p);
			break;
		case 3:inorder(p);
			break;
		case 4:postorder(p);
			break;
		case 5:display(p,lvl);
			break;
		case 6:exit(0);
			break;
		default:printf("Ivalid Selection");
		}
		getch();
	}
}

void insert(struct node **q,int ele)
{
	if(*q==NULL)
	{
		*q=(struct node *)malloc(sizeof(struct node));
		(*q)->l=NULL;
		(*q)->r=NULL;
		(*q)->data=ele;
		return;
	}
	
	else
	{
		if(ele==(*q)->data)
		{
			printf("Duplication Not Allowed");
			getch();
			return;
		}
		else
		{
		if(ele<((*q)->data))
			insert(&((*q)->l),ele);
		else
			insert(&((*q)->r),ele);
		}
	}
	return;
}
void inorder(struct node *q)
{
	if(q!=NULL)
	{
		inorder(q->l);
		printf("%d ",q->data);
		inorder(q->r);
	}
	else
		return;
}

void preorder(struct node *q)
{
	if(q!=NULL)
	{
		printf("%d ",q->data);
		preorder(q->l);
		preorder(q->r);
	}
	else
		return;
}

void postorder(struct node *q)
{
	if(q!=NULL)
	{
		postorder(q->l);
		postorder(q->r);
		printf("%d ",q->data);
	}
	else 
		return;
}
void display(struct node *q,int lvl)
{
	int i;
	if(q==NULL)
		return;
	display((q)->r,lvl+1);
	for(i=0;i<lvl;i++)
		printf(" ");
	printf("%d\n",(q)->data);
	display((q)->l,lvl+1);
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