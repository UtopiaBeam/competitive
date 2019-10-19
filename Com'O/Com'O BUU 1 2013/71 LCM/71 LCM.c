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
    int n,i,a;
    long long LCM=0;
    scanf("%d",&n);
    scanf("%d",&a);
    LCM=a;
    for(i=1;i<n;i++){
        scanf("%d",&a);
        LCM=(a*LCM)/gcd(LCM,a);
    }
    printf("%lld",LCM);

    return 0;
}
