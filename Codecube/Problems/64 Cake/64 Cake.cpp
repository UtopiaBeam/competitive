#include<cstdio>
long long n,a,b,p=0,q=1,gcd,lcm;
long long GCD(long long x,long long y){
    if(x%y)     return GCD(y,x%y);
    return y;
}
int main(){
    scanf("%lld",&n);
    while(n--){
        scanf("%lld/%lld",&a,&b);
        lcm=q*b/GCD(q,b);
        p=a*(lcm/b)+p*(lcm/q);
        q=lcm;
        gcd=GCD(p,q);
        p/=gcd,q/=gcd;
    }
    if(q==1)    printf("%lld\n0\n",p);
    else    printf("%lld\n%lld/%lld\n",p/q+1,(p/q+1)*q-p,q);
    return 0;
}
