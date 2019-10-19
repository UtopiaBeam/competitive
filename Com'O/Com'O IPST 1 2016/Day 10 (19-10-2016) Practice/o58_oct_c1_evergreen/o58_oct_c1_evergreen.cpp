#include<cstdio>
#include<algorithm>
#define L long long
using namespace std;
int n;
L k,a[1002];
bool chk(L m){
    L sum=0,t;
    for(int i=0;i<n;i++){
        if(i<n-1 && a[i]+m>=a[i+1]-m)
            t=(a[i]+m)-(a[i+1]-m)+1;
        else    t=0;
        if(t&1)     sum+=(m+1)*(m+1)-(t/2+1)*(t/2+1);
        else        sum+=(m+1)*(m+1)-(t/2)*(t/2+1);
        if(sum>=k)      return true;
    }
    return false;
}
L bs(L s,L e){
    if(s==e)    return s;
    L m=(s+e)/2;
    if(chk(m))  return bs(s,m);
    return bs(m+1,e);
}
int main(){
    scanf("%d %lld",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%lld",a+i);
    sort(a,a+n);
//    chk(1);
    printf("%lld\n",bs(0,(L)1e9));
    return 0;
}
