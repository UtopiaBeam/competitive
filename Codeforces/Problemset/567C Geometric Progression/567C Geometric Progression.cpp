#include<cstdio>
#include<map>
#define ll long long
using namespace std;
ll ans=0,k,a[200005];
int n;
map<ll,ll> l,r;
int main(){
    scanf("%d %I64d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%I64d",&a[i]);
        r[a[i]]++;
    }
    for(int i=0;i<n;i++){
        ll t=0;
        if(a[i]%k==0)
            t=l[a[i]/k];
        r[a[i]]--;
        ans+=t*r[a[i]*k];
        l[a[i]]++;
    }
    printf("%I64d\n",ans);
    return 0;
}
