#include<stdio.h>
#define MAX 10
struct process
{
    int rem_time;
};
int main()
{
    int nop,i,j,temp,tq,t[MAX],w[MAX],count,sq=0;
    float aw=0,at=0;
    struct process p[MAX],temp;
    printf("Enter the number of process : ");
    scanf("%d",&nop);
    printf("Enter the burst time");
    for(i=0;i<nop;i++)
        scanf("%d",&p[i].rem_time);
    printf("Enter time quantum ");
        scanf("%d",&tq);
    //calculating waiting time
    while(1)
    {
        temp=tq;
        for(i=0,count=0;i<nop;i++)
        {
            if(p[i].rem_time==0)
            {
                count++;
                continue;
            }
            if(p[i].rem_time<tq)
                p[i].rem_time;
        }
    }
    aw=aw/nop;//calculating average
    at=at/nop;
    printf("process\tArrival time\tburst time\twaiting time\tturn around time\n");
    for(i=0;i<nop;i++)
    
    printf("Average waiting time = %f",aw);
    printf("Average turnaround time = %f",at);

    
    return 0;
}