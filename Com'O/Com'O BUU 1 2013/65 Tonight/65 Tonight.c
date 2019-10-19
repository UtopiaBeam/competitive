#include<stdio.h>

int main()
{
    int n,i;
    scanf("%d",&n);
    long long F[n+2];
    F[0]=0; F[1]=1;
    if(n==0)    printf("0\n");
    else if(n==1)   printf("1\n");
    else
    {
        for(i=2;i<=n;i++)
            F[i]=F[i-1]+F[i-2];
        printf("%06lld\n",F[n]%1000000);
    }
    return 0;
}
