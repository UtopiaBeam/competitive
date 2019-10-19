#include<cstdio>
#define ll long long
ll a,b,x,y;
ll bs(ll s,ll e){
    if(s>=e)    return s;
    ll m=(s+e)/2,c1=a-m/y+m/(x*y),c2=b-m/x+m/(x*y);
    if(c1<0)    c1=0;
    if(c2<0)    c2=0;
    if(c1+c2<=m-m/x-m/y+m/(x*y))  return bs(s,m);
    return bs(m+1,e);
}
int main(){
    scanf("%I64d %I64d %I64d %I64d",&a,&b,&x,&y);
    printf("%I64d\n",bs(1,1e18));
    return 0;
}
