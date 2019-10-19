#include<stdio.h>

int main()
{
    int n,i,cnt=0;
    scanf("%d",&n);

    int a[n+2];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++)
    {
        if(a[i]>=80 || (i>0 && (a[i]-a[i-1]>=10) && a[i]>=20))
            cnt++;
    }

    printf("%d",cnt);

    return 0;
}
