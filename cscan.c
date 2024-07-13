#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main()
{
    int size,head,n,s=0;
    printf("Enter the no of requests to be satisfied:");
    scanf("%d",&n);
    int req[n];
    printf("Enter the requests:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("Enter the size:");
    scanf("%d",&size);
    printf("Enter the head:");
    scanf("%d",&head);
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(req[j]>req[j+1])
            {
                int temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }
    }
    
    int dir;
    printf("Enter the direction:\n1.Left\n2.Right\n");
    scanf("%d",&dir);
    
    int index=0;
    for(int i=0;i<n;i++)
    {
        if(req[i]>head)
        {
            index=i;
            break;
        }
    }
    
    if(dir==2)
    {
        for(int i=index;i<n;i++)
        {
            printf("%d->",req[i]);
            s=s+abs(req[i]-head);
            head=req[i];
        }
        s=s+abs(size-1-head);
        head=size-1;
        s=s+abs(0-head);
        head=0;
        for(int i=0;i<index;i++)
        {
            printf("%d->",req[i]);
            s=s+abs(req[i]-head);
            head=req[i];
        }
    }
    
    if(dir==1)
    {
        for(int i=index-1;i>=0;i--)
        {
            printf("%d->",req[i]);
            s=s+abs(req[i]-head);
            head=req[i];
        }
        s=s+abs(0-head);
        head=0;
        s=s+abs(size-1-head);
        head=size-1;
        for(int i=n-1;i>=index;i--)
        {
            printf("%d->",req[i]);
            s=s+abs(req[i]-head);
            head=req[i];
        }
    }

    printf("\nHead movements=%d",s);
}
