#include<cstdio>
#include<algorithm>
using namespace std;
long long mx=0,t,sum=0,n;
int main(){
    scanf("%d",&n);
    sum=n;
    while(n--){
        scanf("%lld",&t);
        sum+=2*t;
        mx=max(t,mx);
    }
    printf("%lld\n",sum+2*mx);
    return 0;
}
