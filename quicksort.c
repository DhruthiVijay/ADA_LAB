#include<stdio.h>
#include<stdlib.h>
void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int low,int high)
{
    int p=arr[low];
    int i=low;
    int j=high;
    while(i<j)
    {
        while(arr[i]<=p && i<=high-1)
        {
            i++;
        }
        while(arr[j]>p && j>=low+1)
        {
            j--;
        }
        if(i<j)
        {
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}
void quickSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
int main()
{
    int num;
    printf("Enter the number of elements: ");
    scanf("%d",&num);
    int arr[num];
    printf("\nEnter the elements: ");
    for(int i=0;i<num;i++)
    {
        scanf("%d",&arr[i]);
    }
    quickSort(arr,0,num-1);
    printf("\nSorted Array: ");
    for(int i=0;i<num;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
