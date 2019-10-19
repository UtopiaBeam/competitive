#include<stdio.h>

int main()
{
    long long n,i,a0,an,q,sum;
    scanf("%lld",&q);

    for(i=0;i<q;i++)
    {
        scanf("%lld %lld",&a0,&an);
        n=an-a0+1;
        sum=(n*(a0+an))/2;
        printf("%lld\n",sum);
    }

    return 0;
}
