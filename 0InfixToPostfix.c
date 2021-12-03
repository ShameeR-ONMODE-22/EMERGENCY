#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
char postfix[100];
char stack[100];
char infix[100];
int top=-1;
void convert()
{
 int i=0,j=-1;
 char data;
 while(infix[i]!='\0')
 {
 data=infix[i];
 if(isalnum(data))
 {
 j++;
 postfix[j]=data;
 }
 else if(data=='(')
 {
 top++;
 stack[top]=data;
 }
 else if(data==')')
 {
 while(stack[top]!='(')
 {
 j++;
 postfix[j]=stack[top];
 top--;
 }
 }
 else
 {
 if(top==-1)
 {
 top=0;
 stack[top]=data;
 }
 else
 {
 while( ( (data=='-'||data=='+') && (stack[top]=='+'||stack[top]=='-'||stack[top]=='*'||stack[top]=='/'||stack[top]=='^') )||( (data=='*'||data=='/')&&(stack[top]=='^'||stack[top]=='*'||stack[top]=='/') ) )
 {
 j++;
 postfix[j]=stack[top];
 top--;
 }
 top++;
 stack[top]=data;
 }
 }
 i++;
 }
 int k;
 for(k=top;k>-1;k--)
 {
 if(stack[k]!='(')
 {
 j++;
 postfix[j]=stack[k];
 }
 }
 j++;
 postfix[j]='\0';
}
void main()
{
 printf("\nEnter the infix expression: ");
 gets(infix);
 convert();
 printf("The converted expression is : ");
 puts(postfix);
}
