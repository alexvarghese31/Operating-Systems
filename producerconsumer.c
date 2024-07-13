#include<stdio.h>
#include<stdlib.h>

int mutex=1,full=0,empty=5,x=0;

void producer()
{
    --mutex;
    ++full;
    --empty;
    x++;
     printf("Producer produces item %d\n",x);
    ++mutex;
}

void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("consumer consumes item %d\n",x);
     x--;
    ++mutex;
}

void main()
{
    int n;
    while(1)
    {
        printf("1.Produce\n2.Consume\n3.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            if(mutex==1 && empty!=0)
            {
                producer();
            }
            else
            {
                printf("Full\n");
            }
            break;
            case 2:
            if(mutex==1 && full!=0)
            {
                consumer();
            }
            else
            {
                printf("Empty\n");
            }
            break;
            case 3:
            exit(0);
            break;
            default:
            printf("Invalid\n");
        }
    }
}
