#include<stdio.h>

int main()
{
    int a[10][10],i,j,sum,t[2],in=0,cnt;
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<9;i++)
    {
        sum=0;  cnt=0;
        for(j=0;j<9;j++)
        {
            sum+=a[i][j];
            if(a[i][j]==0)  cnt++;
        }
        if(cnt==1)
        {
            t[in]=45-sum;
            in++;
        }
    }
    for(i=0;i<9;i++)
    {
        sum=0;  cnt=0;
        for(j=0;j<9;j++)
        {
            sum+=a[j][i];
            if(a[j][i]==0)  cnt++;
        }
        if(cnt==1)
        {
            t[in]=45-sum;
            in++;
        }
    }
    if(t[0]>t[1])
    {
        i=t[0];
        t[0]=t[1];
        t[1]=i;
    }
    printf("%d %d\n",t[0],t[1]);
    return 0;
}
