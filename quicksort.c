#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int l,int r)
{
    int pivot=arr[r];
    int i=l-1,j;
    for(j=l;j<=r-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return (i+1);

}
void quicksort(int arr[],int l,int r)
{
    int split;
    if(l<r)
    {
        split=partition(arr,l,r);
        quicksort(arr,l,split-1);
        quicksort(arr,split+1,r);
    }
}
void print(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
void main()
{
    int arr[500000],n,i;
    clock_t st,et;
    double ts;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        arr[i]=rand();
    }
    printf("before sorting \n");
    print(arr,n);
    quicksort(arr,0,n-1);
    printf("\nafter sorting using quicksort\n");
    print(arr,n);


}