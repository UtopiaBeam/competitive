#include<stdio.h>

int main()
{
    long long q,n,i,piece;
    scanf("%lld",&q);
    for(i=1;i<=q;i++)
    {
        scanf("%lld",&n);
        piece=(n*(n+1))/2+1;
        printf("%lld\n",piece);
    }
    return 0;
}
