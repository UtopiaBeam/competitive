#include<cstdio>
#define ll long long
int t;
ll f(ll x){
    if(x<10)    return x;
    ll sum=0;
    while(x){
        sum+=x%10;      x/=10;
    }
    return f(sum);
}
int main(){
    scanf("%d",&t);
    while(t--){
        ll a,d,l,r,b[12]={},sum=0;
        scanf("%lld %lld %lld %lld",&a,&d,&l,&r);
        ll n=a+((l+8)%9)*d;
        for(int i=0;i<9;i++){
            b[i]=f(n);      sum+=b[i];
            n+=d;
        }
        ll ans=(r-l+1)/9*sum;
        for(int i=0;i<(r-l+1)%9;i++)
            ans+=b[i];
        printf("%lld\n",ans);
    }
    return 0;
}
