#include<stdio.h>
#include<stdlib.h>
int mutex=1,empty=3,full=0,x=0;
int wait(int s)
{
    return (--s);
}
int signal(int s)
{
    return(++s);
}
void producer()
{
    mutex=wait(mutex);
    empty=wait(empty);
    full=signal(full);
    x++;
    printf("Producer produces the item %d\n",x);
    mutex=signal(mutex);

}
void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    printf("Consumer consumes the item %d\n",x);
    x--;
    mutex=signal(mutex);
}

int main()
{
    int coi;
    printf("1. producer\n2. consumer\n3. Exit\n");
    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d",&coi);
        switch (coi)
        {
        case 1:
            if ((mutex == 1) && (empty!=0))
                producer();
            else
                printf("Buffer is full\n");
            break;
        case 2:
            if ((mutex == 1) && (full!=0))
                consumer();
            else
                printf("Buffer is empty");
            break;
        case 3:
            exit(1);
        default:
            printf("Enter valid choice \n");
            break;
        }
    }
    


}