#include<cstdio>
#include<cmath>
#include<algorithm>
#define P pair<int,int>
#define PP pair<P,int>
#define F first
#define S second
using namespace std;
int hs[1000002],a[200002],n,m,l=0,r=0,N,bx,by;
long long ans[200002],cnt=0;
PP q[200002];
bool cmp(PP x,PP y){
    bx=x.F.F/N,by=y.F.F/N;
    return (bx<by) || ((bx==by) && (x.F.S<y.F.S));
}
int main(){
    scanf("%d %d",&n,&m);
    N=sqrt(n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++){
        scanf("%d %d",&q[i].F.F,&q[i].F.S);
        q[i].S=i;
    }
    sort(q,q+m,cmp);
    for(int i=0;i<m;i++){
        while(r<q[i].F.S)
            cnt+=a[++r]*(2*(hs[a[r]]++)+1);
        while(r>q[i].F.S)
            cnt-=a[r]*(2*(--hs[a[r--]])+1);
        while(l<q[i].F.F)
            cnt-=a[l]*(2*(--hs[a[l++]])+1);
        while(l>q[i].F.F)
            cnt+=a[--l]*(2*(hs[a[l]]++)+1);
        ans[q[i].S]=cnt;
    }
    for(int i=0;i<m;i++)
        printf("%I64d\n",ans[i]);
    return 0;
}
