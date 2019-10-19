#include<cstdio>
int gcd(int x,int y){
    if(y==0)    return x;
    if(x%y==0)  return y;
    return gcd(y,x%y);
}
int main(){
    int n,i;
    long long LCM=0,a;
    scanf("%d %lld",&n,&a);
    LCM=a;
    while(--n){
        scanf("%d",&a);
        LCM=(a*LCM)/gcd(LCM,a);
    }
    printf("%lld\n",LCM);
    return 0;
}
