 #include <stdio.h>
#define size 5
void insertion_sort(int arr[], int n);
void main()
{
int arr[size], i, n;
printf("\n Enter how many elements: ");
scanf("%d", &n);
printf("\n Enter array elements: \n");
for(i=0;i<n;i++)
{
scanf("%d", &arr[i]);
}
insertion_sort(arr, n);
printf("\nsorted array : ");
for(i=0;i<n;i++)
printf(" %d\t", arr[i]);
getch();
}
void insertion_sort(int arr[], int n)
{
int i, j, temp;
for(i=1;i<n;i++)
{
temp = arr[i];
j = i-1;
while((temp < arr[j]) && (j>=0))
{
arr[j+1] = arr[j];
j--;
}


arr[j+1] = temp;
int k=0;
for(k;k<n;k++){
	printf("%d\t",arr[k]);
}
printf("\n");
}

}
