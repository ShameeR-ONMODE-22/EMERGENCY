#include<stdio.h>
void main()
{
 int stack[100];
 char array[100];
 int i=0,top=-1;
 char *temp;
 printf("Enter expression: ");
 gets(array);
 temp=array;
 while(*temp!='\0')
 {
 if(isalpha(*temp))
 {
 printf("Enter value of %c",array[i]);
 top++;
 scanf("%d",&stack[top]);
 }
 else
 {
 switch(*temp)
 {
 case '+':
 stack[top-1]=stack[top]+stack[top-1];break;
 case '-':
 stack[top-1]=stack[top-1]-stack[top];break;
 case '*':
 stack[top-1]=stack[top]*stack[top-1];break;
 case '/':
 stack[top-1]=stack[top-1]/stack[top];break;
 case '^':
 stack[top-1]=stack[top]^stack[top-1];break;
 default:
 printf("Invalid input");
 }
 top--;
 }
 i++;
 temp++;
 }
 printf("Result : %d",stack[top]);
}
