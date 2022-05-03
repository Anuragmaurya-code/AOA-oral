#include<stdio.h>
#include<stdlib.h>

void Swap(int *i,int *j)
{
    int temp=*i;
    *i=*j;
    *j=temp;
}
void Selection_Sort(int *Arr,int noe)
{
    int i,j,min;
    for(i=0;i<noe-1;i++)
    {
        min=i;
        for(j=i+1;j<noe;j++)
        {
            if(Arr[j]<Arr[min])
                min=j;
        }
        Swap(&Arr[i],&Arr[min]);
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
    Selection_Sort(Arr,noe);
    for(i=0;i<noe;i++)
        printf("%d ",Arr[i]);
}
