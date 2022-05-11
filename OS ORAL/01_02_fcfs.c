#include<stdio.h>
int main()
{
    int nop,i,b[10],a[10],t[10],w[10],completion=0;
    float aw=0,at=0;
    printf("Enter the number of process : ");
    scanf("%d",&nop);
    printf("Enter the Arrival time and  burst time");
    for(i=0;i<nop;i++)
        scanf("%d %d",&a[i],&b[i]);
    //calculatin waiting time
    for(i=0;i<nop;i++)
    {
        if(i==0)
            w[i]=0;
        else
            w[i]=completion-a[i];
        aw=aw+w[i];
        completion=completion+b[i];
    }
    completion=0;
    for(i=0;i<nop;i++)
    {
        completion+=b[i];
        t[i]=completion-a[i];
        at=at+t[i];
    }
    aw=aw/nop;//calculating average
    at=at/nop;
    printf("process\tburst time\twaiting time\tturn around time\n");
    for(i=0;i<nop;i++)
    printf("  p%d  \t     %d    \t      %d    \t       %d      \n",i+1,b[i],w[i],t[i]);
    printf("Average waiting time = %f",aw);
    printf("Average turnaround time = %f",at);

    
    return 0;
}