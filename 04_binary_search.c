#include<stdio.h>
#include<stdlib.h>
void binary_search(int *Arr,int noe,int data)
{
    int lb=0;
    int ub=noe+1;
    int mid;
    while(lb<=ub)
    {
        mid=(lb+ub)/2;
        if(Arr[mid]==data)
        {
            printf("%d found at %d index",data,mid);
            break;
        }
        else if(Arr[mid]<data)
            lb=mid+1;
        else
            ub=mid-1;
    }
    if(lb>ub)
    printf("%d not found",data);

}
int main()
{
     int noe=5,data;
    int arr[5]={1,3,5,7,9};
    printf("Enter element to be searched in array ");
    scanf("%d",&data);
    binary_search(&arr[0],noe,data);
    return 0;
}