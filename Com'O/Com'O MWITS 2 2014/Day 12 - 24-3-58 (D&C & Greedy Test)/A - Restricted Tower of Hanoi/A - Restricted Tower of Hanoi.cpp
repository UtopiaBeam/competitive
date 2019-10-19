#include<cstdio>
long long n,m;
long long pow(long long a,long long b){
    if(b==0)    return 1;
    long long x=pow(a,b/2);
    if(b%2)     return (x*x*a)%m;
    return (x*x)%m;
}
int main(){
    scanf("%lld %lld",&n,&m);
    printf("%lld\n",(m+pow(3,n)-1)%m);
    return 0;
}
