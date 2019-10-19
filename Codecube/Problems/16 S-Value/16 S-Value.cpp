#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long a[2005],ans=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<2*n;i++)
        scanf("%lld",&a[i]);
    sort(a,a+2*n);
    for(int i=0;i<n;i++)
        ans+=a[i]*a[2*n-1-i];
    printf("%lld\n",ans);
    return 0;
}
