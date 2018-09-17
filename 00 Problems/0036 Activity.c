#include<stdio.h>
long long c,n,r,i,ans=1;
int main(){
    scanf("%I64d",&n);
    r=n/2;
    for(i=n-r+1;i<=n;i++)
        ans*=i;
    for(i=2;i<=r;i++)
        ans/=i;
    if(n%2)     printf("%I64d\n",2*ans);
    else    printf("%I64d\n",ans);
    return 0;
}
