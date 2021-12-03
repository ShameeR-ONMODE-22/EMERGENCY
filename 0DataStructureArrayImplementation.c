#include<stdio.h>
void main()
{
int ar[100];
int i,n,choice,ch,pos,val,flag=0;
printf("Enter how many elements? ");
scanf("%d",&n);
printf("Enter the array elements: ");
for(i=0;i<n;i++)
{
scanf("%d",&ar[i]);
}
printf("Array element are :");
for(i=0;i<n;i++)
{
printf("%d\n",ar[i]);
}
do
{
printf("1. Inserting new element\n2. Deleting a existing element\n3.Searching a element\n4.exit \n Enter your choice : ");
scanf("%d",&choice);
switch(choice)
{

case 1:
Z:
printf("\n1.Insert in begging\n2.Insert in end\n3.Insert in middle \n Enter your choice : ");
scanf("%d",&ch);
if(ch==1)
{
printf("Enter value of element to be inserted: ");
scanf("%d",&val);
for(i=n;i>0;i--)
ar[i]=ar[i-1];
ar[0]=val;
n++;
}
else if(ch==2)
{
printf("Enter value of element to be inserted: ");
scanf("%d",&val);
ar[n]=val;
n++;
}
else if(ch==3)
{
printf("Enter the position and value of element to be inserted: ");
scanf("%d %d",&pos,&val);
for(i=n;i>=pos;i--)
ar[i]=ar[i-1];
ar[pos-1]=val;
n++;
}
else
{
printf("Invalid input.Try again");
goto Z;
}
printf("Array element are :");
for(i=0;i<n;i++)
{
printf("%d\n",ar[i]);
}
break;
case 2:
Y:
printf("1.Delete in begging\n2.Delete in end\n3.Delete in middle \n Enter your choice : ");
scanf("%d",&ch);
if(ch==1)
{
for(i=0;i<n-1;i++)
ar[i]=ar[i+1];
ar[n-1]=NULL;
n--;
}
else if(ch==2)
{
ar[n-1]=NULL;
n--;
}
else if(ch==3)
{
printf("Enter the position to be deleted: ");
scanf("%d",&pos);
for(i=pos-1;i<n;i++)
ar[i]=ar[i+1];
ar[n-1]=NULL;
n--;
}
else
{
printf("Invalid input.Try again");
goto Y;
}
printf("Array element are :");
for(i=0;i<n;i++)
{
printf("%d\n",ar[i]);
}
break;
case 3:
X:
printf("\n1.Search by value\n2.Search by position \n Enter your choice : ");
scanf("%d",&ch);
if(ch==1)
{
printf("Enter value: ");
scanf("%d",&val);
for(i=0;i<n;i++)
{
if(ar[i]==val)
{
printf("position of the element is: %d \n",i+1);
flag=1;
}
}
if(flag==0)
printf("Element not found");
}
else if(ch==2)
{
printf("Enter position: ");
scanf("%d",&pos);
printf("Element in the given position is: %d \n",ar[pos-1]);
}
else
{
printf("Invalid input.Try again");
goto X;
}
case 4:
break;
default:
printf("Wrong input try again ");
break;
}
} while(choice!=4);
}
