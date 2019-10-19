#include<cstdio>
#include<cmath>
#include<algorithm>
#define P pair<int,int>
#define PP pair<P,int>
#define F first
#define S second
using namespace std;
PP q[200002];
int n,m,a[30002],bk,hs[1000002],l=0,r=-1,cnt=0,ans[200002];
bool cmp(PP x,PP y){
    int bx=x.F.F/bk,by=y.F.F/bk;
    return (bx<by) || (bx==by && x.F.S<y.F.S);
}
void add(int x){
    if(!hs[a[x]])   cnt++;
    hs[a[x]]++;
}
void del(int x){
    hs[a[x]]--;
    if(!hs[a[x]])   cnt--;
}
int main(){
    scanf("%d",&n);
    bk=(int)sqrt(n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&q[i].F.F,&q[i].F.S);
        q[i].S=i;
    }
    sort(q,q+m,cmp);
    for(int i=0;i<m;i++){
        while(l<q[i].F.F)   del(l++);
        while(l>q[i].F.F)   add(--l);
        while(r<q[i].F.S)   add(++r);
        while(r>q[i].F.S)   del(r--);
        ans[q[i].S]=cnt;
    }
    for(int i=0;i<m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
