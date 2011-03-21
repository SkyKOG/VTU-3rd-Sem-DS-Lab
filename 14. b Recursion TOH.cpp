#include <stdio.h>
#include <conio.h>

void tower(int n,char sr,char dn,char ax,int *count)
{
	
	if(n==1)
	{
		printf("Move Disc %d From %c to %c Count = %d\n",n,sr,dn,*count);
		(*count)++;
	}
	else
	{
		tower(n-1,sr,ax,dn,count);
		printf("Move Disc %d From %c to %c Count = %d\n",n,sr,dn,*count);
		(*count)++;
		tower(n-1,ax,dn,sr,count);

	}
}

void main()
{
	int n,c=0;
	printf("Enter Number Of Discs : ");
	scanf("%d",&n);
	tower(n,'A','C','B',&c);
	printf("%d",c);
	getch();
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