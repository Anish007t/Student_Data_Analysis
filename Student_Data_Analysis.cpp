#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct student
{
	char name[20];
	int roll;
	float marks;
	float per;
}stu;
void rank(stu[],int);
void grade(int);
float pass(stu[],int);
void result(stu[],int,int);
int main()
{
	stu s[50];
	char ch;
	int i=0,n=0,temp;
	float p;
	printf("\nEnter the students details below:-");
	printf("\n__________________________________\n\n\n");
	do
	{
		n++;
		printf("\nEnter student name=");
		gets(s[i].name);
		fflush(stdin);
		printf("\nEnter student roll=");
		scanf("%d",&s[i].roll);
		fflush(stdin);
		printf("\nEnter student marks=");
		scanf("%f",&s[i].marks);
		fflush(stdin);
		s[i].per=s[i].marks/5;
		printf("\n\nDo you want to continue(y/n)=");
		scanf("%c",&ch);
		fflush(stdin);
		i++;
		printf("\n\n\n");
	}while(ch=='y'||ch=='Y');
	printf("\n.......................................................");
	printf("\n.1)Press 1 for Overall Ranks.                         .");
	printf("\n.2)Press 2 for Overall Pass Percantage of Students.   .");
	printf("\n.3)Press 3 for Find out Result of a Student.          .");
	printf("\n.......................................................");
	printf("\nEnter your choice=");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			rank(s,n);
			break;
		case 2:
			p=pass(s,n);
			printf("\nThe Overall Passing Percantage is=%.2f",p);
			break;
		case 3:
			printf("\nEnter The roll no=");
			scanf("%d",&temp);
			result(s,n,temp);
			break;
		default:
			printf("\nWrong Choice.");
			exit(0);
	}
	getch();
	return 0;
}
void grade(int p)
{
	if(p>=80)
		printf("\n    Grade= 'Star'");
	else if(p>=60 && p<80)
		printf("\n    Grade= '1st Division'");
	else if(p>=45&&p<60)
		printf("\n    Grade= '2nd Division'");
	else if(p>=30&&p<45)
		printf("\n    Grade= '3rd Division'");
	else
		printf("\n    Grade= 'Failed'");
}
void output(stu s[],int i)
{
	printf("\n\n  Name=");
	puts(s[i].name);
	printf("\n    Roll=%d",s[i].roll);
	printf("\n    Marks=%.2f",s[i].marks);
	printf("\n    Percantage=%.2f",s[i].per);
	grade(s[i].per);
}
void rank(stu s[],int n)
{
	int max=0,max2=0,max3=0,i;
	for(i=0;i<n;i++)
		if(s[i].marks>=max)
			max=s[i].marks;
	for(i=0;i<n;i++)
	{
		if(s[i].marks==max)
			continue;
		else if(s[i].marks>=max2)
			max2=s[i].marks;
	}
	for(i=0;i<n;i++)
	{
		if(s[i].marks==max || s[i].marks==max2)
			continue;
		else if(s[i].marks>=max3)
			max3=s[i].marks;
	}
	printf("\n1st Place is:-");
	printf("\n______________");
	for(i=0;i<n;i++)
		if(s[i].marks==max)
			output(s,i);
	printf("\n2nd Place is:-");
	printf("\n______________");
	for(i=0;i<n;i++)
		if(s[i].marks==max2)
			output(s,i);
	printf("\n3rd Place is:-");
	printf("\n______________");
	for(i=0;i<n;i++)
		if(s[i].marks==max3)
			output(s,i);
}
float pass(stu s[],int n)
{
	int i,p=0;
	float temp;
	for(i=0;i<n;i++)
		if(s[i].per>30.00)
			p++;
	temp=(p/n)*100;
	return temp;
}
void result(stu s[],int n,int temp)
{
	int i;
	printf("\nThe Result of the Student is:-");
	printf("\n______________________________");
	for(i=0;i<n;i++)
	{
		if(s[i].roll==temp)
			output(s,i);
	}
}
