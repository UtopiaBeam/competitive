#include<stdio.h>

int main()
{
    int q,i,num,n,s,r,sum[100010];
    scanf("%d",&n);
    sum[0]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d ",&num);
        sum[i]=sum[i-1]+num;
    }
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d %d",&r,&s);
        printf("%d\n",sum[s]-sum[r-1]);
    }

    return 0;
}
