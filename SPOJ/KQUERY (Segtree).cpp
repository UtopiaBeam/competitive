#include<cstdio>
#include<algorithm>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
struct St{
    int s,e,k,in;
};
int st[90002],n,m,ans[200002];
P a[30002];
St q[200002];
bool cmp(St x,St y){
    return x.k > y.k;
}
void ud(int s,int e,int in,int x){
    if(s>e)     return ;
    if(s==e){
        st[in]++;   return ;
    }
    int m=(s+e)/2;
    if(m>=x)    ud(s,m,2*in,x);
    else        ud(m+1,e,2*in+1,x);
    st[in]=st[2*in]+st[2*in+1];
}
int qr(int s,int e,int in,int l,int r){
    if(s>e || l>e || r<s)       return 0;
    if(l<=s && e<=r)    return st[in];
    int m=(s+e)/2;
    return qr(s,m,2*in,l,r)+qr(m+1,e,2*in+1,l,r);
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
            ud(1,n,1,a[idx].S);
            idx++;
        }
        ans[q[i].in]=qr(1,n,1,q[i].s,q[i].e);
    }
    for(int i=0;i<m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
