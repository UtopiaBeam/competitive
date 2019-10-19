#include<stdio.h>
int main(){
    long long m,n,a,ans;
    scanf("%I64d %I64d %I64d",&m,&n,&a);
    if(m%a==0)  ans=m/a;
    else        ans=m/a+1;
    if(n%a==0)  ans*=n/a;
    else        ans*=n/a+1;
    printf("%I64d\n",ans);
    return 0;
}
