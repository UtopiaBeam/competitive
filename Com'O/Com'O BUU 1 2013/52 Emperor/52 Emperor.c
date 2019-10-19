#include<stdio.h>

long long M(long long n)
{
    if(n==0 || n==1)
        return 1;
    if(n%2)
        return M(2*n)+1;
    return M(n/3)*3;
}

int main()
{
    long long n;
    scanf("%lld",&n);

    printf("%lld",M(n));
    return 0;
}
