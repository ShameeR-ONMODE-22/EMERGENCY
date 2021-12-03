#include<stdio.h>
#include<stdlib.h>
int i;
int j;
struct vertex{
int number;
int visited;
};
int stack[10];
int top=-1;
int adjMatrix[10][10];
int vcount=0;
struct vertex* V[20];
int size;

void push(int num)
{
    stack[++top]=num;
}
int pop()
{
    return stack[top--];
}
int peek()
{
    return stack[top];
}
int isempty()
{
    if(top==-1)
        return 0;
    else
        return 1;
}
 void addvertex(int newnum)
 {
     struct vertex* ver=(struct vertex*)malloc(sizeof(struct vertex));
     ver->number=newnum;
     ver->visited=0;
     V[vcount++]=ver;
 }
void displayvertex(int id)
{
    printf(" %d ",V[id]->number);

}
int getunivisited(int id)
{
    int i;
    for(i=0;i<vcount;i++)
    {
        if(adjMatrix[id][i]==1&&V[i]->visited==0)
        {
            return i;
        }
    }
    return -1;
}
void dps()
{
    V[0]->visited=1;
    displayvertex(0);
    push(0);
    while(isempty()!=0)
    {
        int unvisited=getunivisited(peek());
        if(unvisited==-1)
            pop();
        else
        {
            V[unvisited]->visited=1;
            displayvertex(unvisited);
            push(unvisited);
        }
    }
    
    for(i=0;i<size;i++)
        V[i]->visited=0;

}
void main()
{
    int temp,choice,a,b;
    printf("Enter how many elements: ");
    scanf("%d",&size);

    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
           adjMatrix[i][j]=0;

    printf("Enter elements: ");
    for(i=0;i<size;i++)
    {
        scanf("%d",&temp);
        addvertex(temp);
    }
    printf("Enter adjacent matrix: ");
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            printf("Link[");
            displayvertex(i);
            printf("] [");
            displayvertex(j);
            printf("]");
            scanf("%d",&adjMatrix[i][j]);
        }

    }
    printf("Depth first search: ");
    dps();
}
