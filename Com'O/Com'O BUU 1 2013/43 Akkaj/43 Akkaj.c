#include<stdio.h>

int main()
{
    int n,i;
    scanf("%d",&n);
    long long f[n+2];
    f[0]=0; f[1]=1;
    for(i=2;i<=n;i++)
        f[i]=f[i-1]+f[i-2];
    printf("%lld\n",f[n]);
    return 0;
}
