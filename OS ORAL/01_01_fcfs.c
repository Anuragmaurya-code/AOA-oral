#include<stdio.h>
int main()
{
    int nop,i,b[10],t[10],w[10];
    float aw=0,at=0;
    printf("Enter the number of process : ");
    scanf("%d",&nop);
    printf("Enter the burst time");
    for(i=0;i<nop;i++)
        scanf("%d",&b[i]);
    w[0]=0;
    for(i=1;i<nop;i++)
    {
        w[i]=w[i-1]+b[i-1];
        aw=aw+w[i];
    }
    for(i=0;i<nop;i++)
    {
        t[i]=w[i]+b[i];
        at=at+t[i];
    }
    aw=aw/nop;
    at=at/nop;
    printf("process\tburst time\twaiting time\tturn around time\n");
    for(i=0;i<nop;i++)
    printf("  p%d  \t     %d    \t      %d    \t       %d      \n",i+1,b[i],w[i],t[i]);
    printf("Average waiting time = %f",aw);
    printf("Average turnaround time = %f",at);

    
    return 0;
}