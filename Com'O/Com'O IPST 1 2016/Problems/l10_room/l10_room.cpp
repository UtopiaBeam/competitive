#include<cstdio>
#define MOD (long long)(1e6+3)
long long n,k,ans=1;
int main(){
    scanf("%lld %lld",&n,&k);
    if(k>n-k)   k=n-k;
    for(int i=0;i<k;i++){
        ans*=n-i;
        ans/=i+1;
    }
    printf("%lld\n",ans%MOD);
    return 0;
}
