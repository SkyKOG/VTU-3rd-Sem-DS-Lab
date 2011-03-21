#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <windows.h>

struct node 
{
	int item;
	struct node *l;
	struct node *r;
};

struct node *getnode()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	return temp;
}

void addatbeg(struct node **,int);
int del(struct node **,int *);
void addleft(struct node **,int,int);
void display(struct node**);

void main()
{
	struct node *p;
	p=NULL;
	int ele,ch,status=0,key=0;
	while(true)
	{
		system("cls");
		printf("1. Insert At Front\n2. Insert to Left\n3. Detele Node\n4. Display\n5. Exit\n\nEnter Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:printf("Enter Element To Insert : ");
			scanf("%d",&ele);
			addatbeg(&p,ele);
			break;
		case 2:printf("Enter Element To Insert : ");
			scanf("%d",&ele);
			printf("Enter Key To Search On : ");
			scanf("%d",&key);
			addleft(&p,ele,key);
			break;
		case 3:ele=del(&p,&status);
			if(status==0)
			{
				break;
			}
			printf("Element Deleted is : %d",ele);
			break;
		case 4:display(&p);
			break;
		case 5:exit(0);
			break;
		default:printf("Invalid Selection");
		}
		getch();
	}
}

void addatbeg(struct node **q,int ele)
{
	struct node *temp,*r;
	temp=getnode();
	temp->item=ele;
	temp->l=NULL;
	temp->r=NULL;
	if(*q==NULL)
	{
		*q=temp;
		return;
	}
	temp->r=*q;
	(*q)->l=temp;
	(*q)=temp;
}

void addleft(struct node **q,int ele,int key)
{
	struct node *r,*temp;
	int flag=0;
	temp=getnode();
	r=*q;
	if(r==NULL)
	{
		printf("Empty List");
		return;
	}
	if((*q)->item==key)
	{
		addatbeg(q,ele);
		return;
	}
	while(r->r!=NULL)
	{
		if(r->item==key)
		{
			temp->item=ele;
			temp->r=r;
			temp->l=r->l;
			r->l->r=temp;
			r->l=temp;
			flag=1;
		}
		r=r->r;
	}
	if((r->r==NULL)&&(r->item==key))
	{
		temp->item=ele;
		temp->r=r;
		temp->l=r->l;
		r->l->r=temp;
		r->l=temp;
		return;
	}

	if(!flag)
		printf("Key Not Found In List");
}
int del(struct node **q,int *status)
{
	int ele,del;
	printf("Enter Element To Delete : ");
	scanf("%d",&ele);
	struct node *temp;
	temp=*q;
	if(temp==NULL)
	{
		*status=0;
		printf("List Is Empty");
		return NULL;
	}

	if(temp->item==ele)
	{
		*status=1;
		(*q)=(*q)->r;
		del=temp->item;
		free(temp);
		return del;
	}
	while(temp->r!=NULL)
	{
		if(temp->item==ele)
		{
			*status=1;
			del=temp->item;
			temp->l->r=temp->r;
			temp->r->l=temp->l;
			free(temp);
			return del;
		}
		temp=temp->r;
	}
	if((temp->r==NULL)&&(temp->item==ele))
	{
		temp->l->r=NULL;
		*status=1;
		del=temp->item;
		free(temp);
		return del;
	}
	printf("Element Not in List");
	return NULL;
}

void display(struct node **q)
{
	struct node *r;
	r=*q;
	if(r==NULL)
	{
		printf("List Is Empty");
		return;
	}
	while(r!=NULL)
	{
		printf("%d ",r->item);
		r=r->r;
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



