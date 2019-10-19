#include<stdio.h>

int gcd(int x,int y)
{
    if(x%y==0)
        return y;
    else
        return gcd(y,x%y);
}

int main()
{
    int n,i;
    scanf("%d",&n);

    int a,GCD=0;

    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        GCD=gcd(GCD,a);
    }
    printf("%d",GCD);
    return 0;
}
