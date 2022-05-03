#include<stdio.h>
#include<stdlib.h>
struct pair {
    int min;
    int max;
};
struct pair Min_Max(int *Arr,int lb,int ub)
{
    struct pair ans;
    if(lb==ub)
    {
       ans.min=Arr[lb];
       ans.max=Arr[lb]; 
    }
    else if(lb == ub-1)
    {
        if(Arr[lb]<Arr[ub])
        {
            ans.min=Arr[lb];
            ans.max=Arr[ub]; 
        }
        else
        {
            ans.min=Arr[ub];
            ans.max=Arr[lb];
        }
    }
    else
    {
        int mid=(lb+ub)/2;
        struct pair ans1=Min_Max(Arr,lb,mid);
        struct pair ans2=Min_Max(Arr,mid+1,ub);
        if(ans1.min<ans2.min)
            ans.min=ans1.min;
        else
            ans.min=ans2.min;

        if(ans1.max>ans2.max)
            ans.max=ans1.max;
        else
            ans.max=ans2.max;
    }
    return ans;
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
    struct pair answer=Min_Max(Arr,0,noe-1);
    printf("%d is minimum and %d is maximum",answer.min,answer.max);
    
}