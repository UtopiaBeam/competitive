#include<cstdio>
#include<algorithm>
#define P pair<int,int>
#define F first
#define S second
struct St{
    int s,e,k,in;
};
using namespace std;
int ft[30002],n,m,ans[200002];
P a[30002];
St q[200002];
bool cmp(St x,St y){
    return x.k > y.k;
}
void ud(int x){
    for(;x<=n;x+=-x&x)  ft[x]++;
}
int gs(int x){
    int sum=0;
    for(;x;x-=-x&x)     sum+=ft[x];
    return sum;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].F);
        a[i].F*=-1;     a[i].S=i+1;
    }
    sort(a,a+n);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&q[i].s,&q[i].e,&q[i].k);
        q[i].in=i;
    }
    sort(q,q+m,cmp);
    int idx=0;
    for(int i=0;i<m;i++){
        while(idx<n && -a[idx].F>q[i].k){
            ud(a[idx].S);
            idx++;
        }
        ans[q[i].in]=gs(q[i].e)-gs(q[i].s-1);
    }
    for(int i=0;i<m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
