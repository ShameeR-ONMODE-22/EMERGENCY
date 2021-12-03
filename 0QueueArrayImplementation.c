#include<stdio.h>
int ar[100];
int rear=-1,front=-1;
void enqueue()
{
 int val;
 if(rear==100)
 printf("Overflow");
 else if(rear==-1 && front==-1)
 {
 printf("Enter first value in queue: ");
 scanf("%d",&val);
 rear=0;
 front=0;
 ar[rear]=val;
 }
 else
 {
 printf("Enter value: ");
 scanf("%d",&val);
 rear++;
 ar[rear]=val;
 }
}
void dequeue()
{
 if(front == -1)
printf("Queue is empty");
else if(front==rear)
{
printf("Last element is deleted");
printf("\nDeleted element is: %d",ar[front]);
front=-1;
rear=-1;
}
else
{
 printf("Deleted element : %d",ar[front]);
  front++;
}
}
void display()
{
 int i;
 printf("Array elements are: ");
 for(i=front;i<=rear;i++)
 {
 printf(" %d ",ar[i]);
 }
}
void main()
{
 int ch;
 do
 {
 printf("\nMenu\n\n1.Enqueue\t\t\t2.dequeue\n3.Display\t\t\t4.Exit\nEnter your choice: ");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 enqueue();
 break;
 case 2:
 dequeue();
 break;
 case 3:
 display();
 break;
 case 4:
 break;
 default:
 printf("Invalid input. Try again");
 }
 }while(ch!=4);
}
