#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,i;
    long long a[810],b[810],ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    sort(a,a+n);
    for(i=0;i<n;i++)
        scanf("%lld",&b[i]);
    sort(b,b+n);
    for(i=0;i<n;i++)
        ans+=a[i]*b[i];
    printf("%lld\n",ans);
    return 0;
}
