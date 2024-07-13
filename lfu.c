#include<stdio.h>
#define framesize 3

int frame[framesize];
int frequency[framesize];

void initialise()
{
    for(int i=0;i<framesize;i++)
    {
        frame[i]=-1;
        frequency[i]=0;
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

int lfuindex()
{
    int min=frequency[0];
    int lfuindex=0;
    for(int i=1;i<framesize;i++)
    {
        if(frequency[i]<min)
        {
            min=frequency[i];
            lfuindex=i;
        }
    }
    return lfuindex;
}

void lfu(int page[],int n)
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
                frequency[j]++;
                break;
            }
        }
        if(found==0)
        {
            pf++;
            int index=lfuindex();
            frame[index]=currpage;
            frequency[index]=1;
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
    lfu(page,n);
}
