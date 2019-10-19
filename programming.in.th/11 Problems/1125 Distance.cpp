#include<cstdio>
#include<algorithm>
using namespace std;
long long x[500005],y[500005],ans=0;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld %lld",&x[i],&y[i]);
    sort(x,x+n);    sort(y,y+n);
    for(int i=0;i<n/2;i++)
        ans+=(n-1-2*i)*(x[n-1-i]-x[i]+y[n-1-i]-y[i]);
    printf("%lld\n",ans);
    return 0;
}
