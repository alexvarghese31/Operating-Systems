#include <stdio.h>

void findwt(int p[],int n,int at[],int bt[],int wt[],int ct[],int q)
{
    int rt[n];
    for(int i=0;i<n;i++)
    {
        rt[i]=bt[i];
    }
    
    int t=0;
    while(1)
    {
        int done=1;
        for(int i=0;i<n;i++)
        {
            if(rt[i]>0)
            {
                done=0;
                if(rt[i]>q)
                {
                    t=t+q;
                    rt[i]-=q;
                }
                else
                {
                    t=t+rt[i];
                    wt[i]=t-bt[i]-at[i];
                    ct[i]=t;
                    rt[i]=0;
                }
            }
        }
        
        if(done==1)
        {
            break;
        }
    }
}

void findtat(int p[],int n,int at[],int bt[],int wt[],int tat[])
{
    for(int i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
    }
}

void sortAT(int p[],  int n, int at[], int bt[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
                // Swap arrival times
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap burst times
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap process numbers
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void findavg(int p[],int n,int at[],int bt[],int q)
{
    int tat[n],wt[n],ct[n],twt=0,ttat=0;
    findwt(p,n,at,bt,wt,ct,q);
    findtat(p,n,at,bt,wt,tat);
    printf("\nPNO\tAT\tBT\tCT\tTAT\tWT");
    for(int i=0;i<n;i++)
    {
        twt+=wt[i];
        ttat+=tat[i];
        printf("\n%d\t%d\t%d\t%d\t%d\t%d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAVG TAT=%2f",(float)ttat/n);
    printf("\nAVG WT=%2f",(float)twt/n);
}

void main()
{
    int n;
    printf("Enter the no of processes:");
    scanf("%d",&n);
    int p[n],at[n],bt[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the process no:");
        scanf("%d",&p[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("Enter the arrival time of process %d: ",i+1);
        scanf("%d",&at[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("Enter the burst time of process %d: ",i+1);
        scanf("%d",&bt[i]);
    }
    int q=5;
    sortAT(p,n,at,bt);
    findavg(p,n,at,bt,q);
}
