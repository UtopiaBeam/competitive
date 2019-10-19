#include<cstdio>
long long n;
long long f(long long n){
    if(n<2)     return 1;
    if(n%2)     return f(2*n)+1;
    return f(n/3)*3;
}
int main(){
    scanf("%lld",&n);
    printf("%lld\n",f(n));
    return 0;
}
