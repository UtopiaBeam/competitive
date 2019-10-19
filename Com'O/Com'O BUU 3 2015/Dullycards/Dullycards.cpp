#include<cstdio>
#include<algorithm>
#define MOD 1000000007
using namespace std;
int n=10000,k=5000;
long long a[10002],ans=0,t=1;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n;i++)
        a[i]%=MOD;
    for(int i=k-1;i<n;i++){
        ans+=a[i]*t;
        ans%=MOD;
        t*=i+1;     t/=i-k+2;
        t%=MOD;
    }
    printf("%lld\n",ans);
    return 0;
}
