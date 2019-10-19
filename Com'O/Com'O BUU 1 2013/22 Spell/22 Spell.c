#include<stdio.h>

int main()
{
    int a,b,c,q,r;
    scanf("%d %d %d",&a,&b,&c);
    r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }                               //gcd(a,b)=b
    if(c%b==0)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}
