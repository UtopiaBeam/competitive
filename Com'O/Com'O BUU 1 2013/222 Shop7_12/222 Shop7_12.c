#include<stdio.h>

int main()
{
    int a,b,n,i,j,k,change,index=0,t;
    scanf("%d %d %d",&a,&b,&n);
    int ans[15000];
    for(i=0;i<n;i++)
        scanf("%d",&change);
    if(a>b) t=a,a=b,b=t;
    t=a;
    while(change<t)    t+=a;
    if(change==t)
    {
        printf("%d\n",t);
        return 0;
    }
    else
    {
        t=t--;
    }

    return 0;
}
