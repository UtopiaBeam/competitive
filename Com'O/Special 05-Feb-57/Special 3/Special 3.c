#include<stdio.h>
long long num[50010],ans;
long long gcd(int a,int b){
    if(a%b==0)    return b;
    return gcd(b,a%b);
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&num[i]);
    ans=num[0];
    for(i=1;i<n;i++)
        ans=(ans*num[i])/gcd(ans,num[i]);
    printf("%lld\n",ans);
    return 0;
}
