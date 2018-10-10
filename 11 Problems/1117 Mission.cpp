#include<cstdio>
#include<algorithm>
using namespace std;
long long a[100005],Max,n;
bool cmp(long long p,long long q){ return p>q; }
int main(){
    scanf("%d",&n);
    for(long long i=0;i<n;i++){
        long long A,B;
        scanf("%lld %lld",&A,&B);
        a[i]=B-2*A;
    }
    sort(a,a+n,cmp);
    for(long long i=1;i<n;i++)
        a[i]+=a[i-1];
    Max=(-1)*n*n;
    for(long long i=0;i<n;i++)
        Max=max(Max,a[i]-(n-i-1)*(n-i-1));
    printf("%lld\n",Max);
    return 0;
}
