#include<stdio.h>
#include<math.h>

int main()
{
    long long n;
    long long i,ans=0;
    scanf("%lld",&n);
    for(i=1;pow(5,i)<=n;i++)
    {
        ans+=floor(n/pow(5,i));
    }

    printf("%lld\n",ans);
    return 0;
}
