#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main()
{
    int head,n;
    printf("Enter the no of requests to be satisfied:");
    scanf("%d",&n);
    int req[n];
    printf("Enter the requests:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("Enter the head:");
    scanf("%d",&head);
    
    int s=0;
    printf("The sequence is:\n");
    for(int i=0;i<n;i++)
    {
        s=s+abs(head-req[i]);
        head=req[i];
        printf("%d",req[i]);
        if(i<(n-1))
        {
            printf("->");
        }
    }
    printf("\nHead movements=%d",s);
}
