#include<cstdio>
#define L long long
L a,b;
L bs(L s,L e){
    if(s>e)    return -1;
    L p=(s+e)/2,q=a-p;
    if(p*q/q!=p)    return bs(s,p-1);
    if(p*q==b)      return p;
    if(p*q>b)       return bs(s,p-1);
    return bs(p+1,e);
}
int main(){
    scanf("%lld %lld",&a,&b);
    L x=bs(1,a/2);
    if(x<0)     printf("Goodbye T-T");
    else        printf("%lld %lld\n",x,a-x);
    return 0;
}
