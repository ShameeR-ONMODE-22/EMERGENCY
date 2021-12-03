#include<stdio.h>

void topo (int G[20][20] ,int size);
int visited[20];
int main()
{
	int i,j,size,G[20][20];
	printf("ENTER THE SIZE OF THE MATRIX\n");
	scanf("%d",&size);
	printf("ENTER THE ADJACENCY OF THE MATRIX :\n");
	for (i=0;i<size;i++)
	{
    	for (j=0;j<size;j++)
	 	{
	 		scanf("%d",&G[i][j]);
	 	}
	 }




	for (i=0;i<size;i++)
	{
		visited[i]=0;
	}

	printf("Topological sorting are: \n");
  topo(G, size);

  return 0;
}

void topo (int G[20][20],int size)
{
	int i,k,j;
  for (k = 0; k < size; k++) {
    int count = 0, node = -1;
    for (i = 0; i < size; i++) {
      count = 0;
      for( j = 0; j < size; j++) {
        if(G[j][i] == 0 && !visited[i]) {
          count++;
        }
      }
    
      if (count == size) {
        node = i;
        visited[node] = 1;
        break;
      }
    }
    printf("%d\n", node);
int i;
    for (i = 0; i < size; i++) 
      G[node][i] = 0;
  }
}
