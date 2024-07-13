#include<stdio.h>
#define framesize 3

int frame[framesize];
int timestamp[framesize];
int t=0;

void initialise()
{
    for(int i=0;i<framesize;i++)
    {
        frame[i]=-1;
        timestamp[i]=-1;
    }
}

void display()
{
    for(int i=0;i<framesize;i++)
    {
        if(frame[i]!=-1)
        {
            printf("%d",frame[i]);
        }
        else
        {
            printf("-");
        }
    }
    printf("\n");
}

int lruindex()
{
    int min=timestamp[0];
    int lruindex=0;
    for(int i=1;i<framesize;i++)
    {
        if(timestamp[i]<min)
        {
            min=timestamp[i];
            lruindex=i;
        }
    }
    return lruindex;
}

void lru(int page[],int n)
{
    int pf=0;
    for(int i=0;i<n;i++)
    {
        int currpage=page[i];
        int found=0;
        for(int j=0;j<framesize;j++)
        {
            if(frame[j]==currpage)
            {
                found=1;
                timestamp[j]=t++;
                break;
            }
        }
        if(found==0)
        {
            pf++;
            int index=lruindex();
            frame[index]=currpage;
            timestamp[index]=t++;
        }
         display();
    }
    
    printf("No of pagefaults=%d ",pf);
}

void main()
{
    int n;
    printf("Enter the no: of pages:");
    scanf("%d",&n);
    int page[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the page:");
        scanf("%d",&page[i]);
    }
    initialise();
    lru(page,n);
}
