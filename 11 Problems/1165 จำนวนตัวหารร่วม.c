#include<stdio.h>
#include<math.h>
long long GCD;

long long gcd(long long a,long long b)
{
    if(a%b) return gcd(b,a%b);
    else    return b;
}

int main()
{
    long long n,i,cnt=0;
    scanf("%lld",&n);
    long long num[n+2];
    for(i=0;i<n;i++)
        scanf("%lld",&num[i]);

    GCD=0;
    for(i=0;i<n;i++)
    {
        GCD=gcd(GCD,num[i]);
    }
    for(i=1;i<=sqrt(GCD);i++)
    {
        if(!(GCD%i))
            if(GCD/i==i)    cnt++;
            else            cnt+=2;
    }
    printf("%d\n",cnt);
    return 0;
}

