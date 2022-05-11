#include<stdio.h>
#define MAX 10
struct process
{
    int pro;
    int a;
    int b;
};
int main()
{
    int nop,i,j,t[MAX],w[MAX],completion=0;
    float aw=0,at=0;
    struct process p[MAX],temp;
    printf("Enter the number of process : ");
    scanf("%d",&nop);
    printf("Enter the process, Arrival time and  burst time");
    for(i=0;i<nop;i++)
        scanf("%d %d %d",&p[i].pro,&p[i].a,&p[i].b);

    //applying bubble sort by process

    for(i=0;i<nop;i++)
    {
        for(j=0;j<nop-i-1;j++)
        {
            if(p[j].b>p[j+1].b)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    //calculating waiting time
    for(i=0;i<nop;i++)
    {
        if(i==0)
            w[i]=0;
        else
            w[i]=completion-p[i].a;
        aw=aw+w[i];
        completion=completion+p[i].b;
    }
    completion=0;
    for(i=0;i<nop;i++)
    {
        completion+=p[i].b;
        t[i]=completion-p[i].a;
        at=at+t[i];
    }
    aw=aw/nop;//calculating average
    at=at/nop;
    printf("process\tArrival time\tburst time\twaiting time\tturn around time\n");
    for(i=0;i<nop;i++)
    printf("  p%d  \t     %d      \t     %d   \t       %d   \t        %d       \n",p[i].pro,p[i].a,p[i].b,w[i],t[i]);
    printf("Average waiting time = %f",aw);
    printf("Average turnaround time = %f",at);

    
    return 0;
}