#include<stdio.h>
#include<stdlib.h>
void swap(int *i,int *j)
{
    int temp=*i;
    *i=*j;
    *j=temp;
}
int partition(int *arr,int lb,int ub)
{
    int pivot=lb;
    while(lb<=ub)
    {
        while(arr[lb]<=arr[pivot])
            lb++;
        while(arr[ub]>arr[pivot])
            ub--;
        if(lb<ub)
            swap(&arr[lb],&arr[ub]);
    }
    swap(&arr[pivot],&arr[ub]);
    return ub;
}
void Quick_Sort(int *arr,int lb,int ub)
{
    if(lb<ub)
    {
        int loc=partition(arr,lb,ub);
        Quick_Sort(arr,lb,loc-1);
        Quick_Sort(arr,loc+1,ub);
    }
}
int main()
{
    int noe,i;
    printf("Enter the number of elements in array ");
    scanf("%d",&noe);
    int *Arr;
    Arr=(int *)malloc(noe*sizeof(int));
    printf("Enter the elements \n");
    for(i=0;i<noe;i++)
    {   
        scanf("%d",&Arr[i]);
    }
    Quick_Sort(Arr,0,noe);
    for(i=0;i<noe;i++)
        printf("%d ",Arr[i]);
}