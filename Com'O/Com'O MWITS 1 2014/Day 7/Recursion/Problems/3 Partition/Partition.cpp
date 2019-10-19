#include<stdio.h>
long long par(int n,int k){
    long long ans=0;
    if(n<k)              return 0;
    if(k>=n-1||k==1)     return 1;
    for(int i=1;i<=k;i++)
        ans+=par(n-k,i);
    return ans;
}
int main(){
    long long ans=0;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        ans+=par(n,i);
    printf("%lld\n",ans);
    return 0;
}
