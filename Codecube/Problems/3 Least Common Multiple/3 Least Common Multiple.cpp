#include<cstdio>
long long a,b;
long long gcd(long long x,long long y){
    if(y==0)    return x;
    if(x%y)     return gcd(y,x%y);
    return y;
}
int main(){
    scanf("%lld %lld",&a,&b);
    printf("%lld\n",(a*b)/gcd(a,b));
    return 0;
}
