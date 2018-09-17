#include<cstdio>
int n,k;
long long a[100005]={1,1},sum=1;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=2;i<=n;i++){
        sum+=a[i-1];
        if(i>k)     sum-=a[i-k-1];
        sum=(sum+2009)%2009,a[i]=sum%2009;
    }
    printf("%lld\n",a[n]);
    return 0;
}
