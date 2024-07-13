#include<stdio.h>

int main()
{
int i,j,k,n,m,c=0;
printf("Enter the no: of processes:");
scanf("%d",&n);
printf("Enter the no: of resources:");
scanf("%d",&m);
int alloc[n][m],max[n][m],avail[m];

printf("Enter the Allocation matrix\n");
for(i=0;i<n;i++)
{
    for(j=0;j<m;j++)
    {
        scanf("%d",&alloc[i][j]);
    }
}

printf("Enter the Maximum matrix\n");
for(i=0;i<n;i++)
{
    for(j=0;j<m;j++)
    {
        scanf("%d",&max[i][j]);
    }
}

printf("Enter the availibility of resources:\n");
for(i=0;i<m;i++)
{
    scanf("%d",&avail[i]);
}

int finish[n],work[m],need[n][m],safesequence[n];
for(i=0;i<n;i++)
{
    finish[i]=0;
}
for(i=0;i<m;i++)
{
    work[i]=avail[i];
}
for(i=0;i<n;i++)
{
    for(j=0;j<m;j++)
    {
        need[i][j]=max[i][j]-alloc[i][j];
    }
}
printf("The need matrix is:\n");
for(i=0;i<n;i++)
{
    for(j=0;j<m;j++)
    {
        printf("%d ",need[i][j]);
    }
    printf("\n");
}

for(k=0;k<n;k++)
{
    for(i=0;i<n;i++)
    {
        if(finish[i]==0)
        {
            int flag=0;
            for(j=0;j<m;j++)
            {
                if(need[i][j]>work[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                safesequence[c]=i;
                c++;
                for(int y=0;y<m;y++)
                {
                    work[y]+=alloc[i][y];
                }
                finish[i]=1;
            }
        }
    }
}

printf("The Safe sequence is:\n");
for(i=0;i<n;i++)
{
    printf("%d ",safesequence[i]);
}
}
