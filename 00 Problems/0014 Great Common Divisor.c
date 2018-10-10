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
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",gcd(a,b));

    return 0;
}
