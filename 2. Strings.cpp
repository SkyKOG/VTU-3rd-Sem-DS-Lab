#include <stdio.h>
#include <conio.h>
#include <windows.h>

void newstrcpy(char *,char *);
void newstrcat(char *,char *);

void main()
{
	char str1[20],str2[20],str3[20];
	printf("Enter First String : ");
	gets(str1);
	printf("String 3 After Copying String 1 : ");
	newstrcpy(str1,str3);
	puts(str3);
	printf("Enter Second String :");
	gets(str2);
	printf("String 3 After Concatenation : ");
	newstrcat(str3,str2);
	puts(str3);
	getch();
}
void newstrcpy(char *p,char *q)
{
	while(*q++=*p++);
}
void newstrcat(char *p,char *q)
{
	while(*p)
		p++;
	(*p)=" ";
	p++;
	while(*p++=*q++);
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