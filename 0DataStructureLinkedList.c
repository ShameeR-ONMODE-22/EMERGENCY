#include <stdio.h>
#include <stdlib.h>
typedef struct node* ptr;
struct Node
{
      int data;
      struct Node  *next;
};


void insertAtBeginning(ptr* head, int new_data)
{

      struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
      new_node->data = new_data;
      new_node->next = (*head);
      *head = new_node;
}


void insertMiddle(struct Node* prev_node, int new_data)
{
      if (prev_node == NULL)
        {
            printf("the given previous node cannot be NULL");
        }

      struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
      new_node->data = new_data;
      new_node->next = prev_node->next;
      prev_node->next = new_node;
}


void insertAtEnd(ptr* head, int new_data)
{
      struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
      struct Node* last = *head;
      new_node->data = new_data;
      new_node->next = NULL;
      if (*head == NULL)
        {
            *head = new_node;
            return;
        }
      while (last->next != NULL)
        last = last->next;

      last->next = new_node;
      return;
}


void deleteNode(ptr* head, int key)
{
      struct Node *temp = *head, *prev;
      if (temp != NULL && temp->data == key)
      {
      *head = temp->next;
      free(temp);
      return;
      }
      while (temp != NULL && temp->data != key) {
      prev = temp;
      temp = temp->next;
      }
      if (temp == NULL)
      return;
      prev->next = temp->next;
      free(temp);
}


int searchNode(ptr* head, int key)
{
      struct Node* current = *head;
      int pos=0;
      while (current != NULL)
      {
            pos++;
            if (current->data == key)
                return pos;
            current = current->next;
      }
      return 0;
}


void printList(struct Node* node)
{
      while (node != NULL)
      {
      printf(" %d ", node->data);
      node = node->next;
      }
}


int main()
{
    int ch,x,a,z,i,pre;
    struct Node* head = NULL;
    struct Node* curr =NULL;
    printf("Linked list\n");
    printList(head);
   do
    {
    M:
    printf("\n1.Insertion\n2.deletion\n3.Search\n4.Display\n5.Exit\n\n");
    printf("\nEnter Your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
            printf("1.Beginning\n2.End\n3.Middle");
            printf("\nEnter Your choice:");
            scanf("%d",&x);
                    if(x==1)
                        {

                        printf("Enter the element:");
                        scanf("%d",&a);
                        insertAtBeginning(&head, a);
                        printf("Linked list: ");
                        printList(head);
                        break;
                        }
                    else if(x==2)
                        {
                            printf("Enter the element");
                            scanf("%d",&a);
                            insertAtEnd(&head, a);
                            printf("Linked list: ");
                            printList(head);
                            break;
                        }
                    else if(x==3)
                        {
                            printf("Enter position after which the given element should be inserted by seeing the List: ");
                            printList(head);
                            scanf("%d",&pre);
                            printf("Enter the element");
                            scanf("%d",&a);
                            curr=head;
                            for(i=2;i<pre;i++)
                                curr=curr->next;
                            insertMiddle(curr, a);
                            printf("Linked list: ");
                            printList(head);
                            break;
                        }
                    else
                        printf("Invalid input");
                break;
        case 2:
            if(head==NULL)
            {
                printf("\nlist is empty\n");
                goto M;
            }
            printf("1.Beginning\n2.End\n3.Middle");
            printf("\nEnter Your choice:");
            scanf("%d",&x);
                    if(x==1)
                        {
                        deleteNode(&head, head->data);
                        printf("\nAfter deleting an element: ");
                        printList(head);
                        break;
                        }
                    else if(x==2)
                        {
                            curr=head;

                            while(curr->next!=NULL)
                                curr=curr->next;

                            deleteNode(&head,curr->data);
                            printf("\nAfter deleting an element: ");
                            printList(head);
                            break;
                        }
                    else if(x==3)
                        {
                            printf("Enter which element should be deleted by seeing the List: ");
                            printList(head);
                            scanf("%d",&pre);
                            deleteNode(&head, pre);
                            printf("\nAfter deleting an element: ");
                            printList(head);
                            break;
                        }
                     else
                        printf("Invalid input");
                    break;

        case 3:

            printf("1.Search by value\n2.Search by position: ");
            scanf("%d",&z);
            if(z==1)
            {
                printf("\nEnter the element:");
                scanf("%d",&a);
                int item_to_find = a;
                a=searchNode(&head, item_to_find);
                if(a!=0)
                {
                    printf("\n%d is found at position %d", item_to_find,a);
                }
                else
                {
                    printf("\n%d is not found", item_to_find);
                }
            }
            else if(z==2)
            {
                printf("Enter position: ");
                scanf("%d",&a);
                struct Node *newnode;
                newnode=(struct Node*)malloc(sizeof(struct Node));
                newnode=head;
                for(i=1;i<a;i++)
                {
                    newnode=newnode->next;
                }
                printf("Element in %d position is %d",a,newnode->data);
            }

        case 4:
            printList(head);



  }
}while(ch!=5);





}

