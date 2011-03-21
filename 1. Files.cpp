#include <stdio.h>
#include <conio.h>
#include <windows.h>

typedef struct 
{
	int usn;
	char name[20];
	int m1,m2,m3;
}rec;

void display_rec(rec t)
{
	printf("%d\t%s\t%d\t%d\t%d\n",t.usn,t.name,t.m1,t.m2,t.m3);
}
void store_rec(FILE *fp)
{
	rec t;
	printf("Enter USN : ");
	scanf_s("%d",&t.usn);
	fflush(stdin);
	printf("Enter The Name : ");
	gets_s(t.name);
	printf("Enter Marks of 3 Subjects : ");
	scanf_s("%d%d%d",&t.m1,&t.m2,&t.m3);  
	fwrite(&t,sizeof(rec),1,fp);
}
void display_all(FILE *fp)
{
	rec t;
	printf("\nUSN\tName\tm1\tm2\tm3\n");
	while(true)
	{
		fread(&t,sizeof(rec),1,fp);
		if(feof(fp))
			break;

		display_rec(t);
	}
}
void search(FILE *fp)
{
	int key,found=0;
	rec t;
	printf("Enter USN Number To Be Searched On : ");
	scanf("%d",&key);
	while(true)
	{
		fread(&t,sizeof(rec),1,fp);
		if(feof(fp))
			break;
		if(key==t.usn)
		{
			printf("\nUSN\tName\tm1\tm2\tm3\n");
			found=1;
			display_rec(t);
		}
	}
	if(!found)
		printf("Record Not Found");
}

void main()
{
	int ch=0,flag=1;
	FILE *fp;
	while(flag)
	{
		system("cls");
		printf("\n1.Add Record\n2.Display All\n3.Search\n4.Exit");
		printf("\n\nEnter Yer Choice : ");
		scanf_s("%d",&ch);
		switch(ch)
		{
		case 1:fp=fopen("sky.dat","a+b");
			store_rec(fp);
			fclose(fp);
			break;
		case 2:fp=fopen("sky.dat","r+b");
			display_all(fp);
			fclose(fp);
			break;
		case 3:fp=fopen("sky.dat","r+b");
			search(fp);
			fclose(fp);
			break;
		case 4:default:flag=0;
		}
		_getch();
		system("cls");
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

			