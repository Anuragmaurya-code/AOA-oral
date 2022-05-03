#include<stdio.h>
#include<stdlib.h>
void Linear_Search(int *arr,int noe,int value)
{
    int i;
    for(i=0;i<noe;i++)
    {
        if(arr[i]==value)
        { 
            printf("%d found at index position %d",value,i);
        }
    }
    if(i==noe)
        printf("%d not found in array",value);
}
int main()
{
    int noe=5,data;
    int arr[5]={5,6,9,1,3};
    printf("Enter element to be searched in array ");
    scanf("%d",&data);
    Linear_Search(&arr[0],noe,data);
}