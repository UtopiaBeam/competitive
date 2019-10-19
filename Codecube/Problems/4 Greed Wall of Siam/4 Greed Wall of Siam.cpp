#include<cstdio>
int n;
long long a,sum=0,GCD=0;
long long gcd(long long x,long long y){
    if(y==0)    return x;
    if(x%y)     return gcd(y,x%y);
    return y;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a);
        sum+=a;
        GCD=gcd(GCD,a);
    }
    printf("%lld\n",sum/GCD);
    return 0;
}
