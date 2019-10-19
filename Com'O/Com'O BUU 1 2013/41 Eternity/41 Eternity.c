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
    int n,i,q,a,p,k;
    scanf("%d %d",&n,&q);

    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        p=a/gcd(a,q);
        k=q/gcd(a,q);
        printf("%d/%d\n",p,k);
    }
    return 0;
}
