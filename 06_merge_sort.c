#include<stdio.h>
#include<stdlib.h>
void Merge(int *Arr,int lb,int mid,int ub)
{
    int i=lb,j=mid+1,k=lb;
    int New_Arr[ub+1];
    while(i<=mid && j<=ub)
    {
        if(Arr[i]<=Arr[j])
        {
            New_Arr[k]=Arr[i];
            i++;
            k++;
        }
        else
        {
            New_Arr[k]=Arr[j];
            j++;
            k++;
        }
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            New_Arr[k]=Arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i<=mid)
        {
            New_Arr[k]=Arr[i];
            i++;
            k++;
            
        }
        
    }
    for(k=lb;k<=ub;k++)
        Arr[k]=New_Arr[k];
}
void Merge_Sort(int *Arr,int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        Merge_Sort(Arr,lb,mid);
        Merge_Sort(Arr,mid+1,ub);
        Merge(Arr,lb,mid,ub);

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
        scanf("%d",&Arr[i]);
    Merge_Sort(Arr,0,noe);
    for(i=0;i<noe;i++)
        printf("%d ",Arr[i]);
}