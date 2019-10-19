#include<cstdio>
#define L long long
int n;
L gcd=0,cnt=0,a;
L GCD(L x,L y){
    if(y==0)    return x;
    if(x%y)     return GCD(y,x%y);
    return y;
}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%lld",&a);
        gcd=GCD(gcd,a);
    }
    for(int i=1;i*i<=gcd;i++)
        if(i*i==gcd)    cnt++;
        else if(gcd%i==0)   cnt+=2;
    printf("%lld\n",cnt);
    return 0;
}
