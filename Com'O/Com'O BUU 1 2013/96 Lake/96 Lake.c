#include<stdio.h>

long long main()
{
    long long q,i,sum=0;
    scanf("%lld",&q);

    long long a[q+2],b[q+2];
    for(i=0;i<q;i++)
    {
        scanf("%lld %lld",&a[i],&b[i]);
        if(a[i]%2)
            a[i]++;
        if(b[i]%2)
            b[i]--;
    }

    for(i=0;i<q;i++)
    {
        sum=((b[i]-a[i])/2+1)*(a[i]+b[i])/2;
        printf("%lld\n",sum);
    }

    return 0;
}
