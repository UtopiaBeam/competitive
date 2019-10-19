#include<cstdio>
#include<algorithm>
#define P pair<int,int>
#define PP pair<P,int>
#define F first
#define S second
using namespace std;
int p[1000002],n,m,a[30002],ft[1000002],ans[200002];
PP q[200002];
bool cmp(PP a,PP b){
    return a.F.S<b.F.S;
}
void ud(int x,int v){
    for(;x<=n;x+=-x&x)  ft[x]+=v;
}
int qr(int x){
    int sum=0;
    for(;x;x-=-x&x)     sum+=ft[x];
    return sum;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&q[i].F.F,&q[i].F.S);
        q[i].S=i;
    }
    sort(q,q+m,cmp);
    for(int i=1,j=0;i<=n && j<m;i++){
        if(p[a[i]])     ud(p[a[i]],-1);
        p[a[i]]=i;
        ud(i,1);
        while(j<m && q[j].F.S==i){
            ans[q[j].S]=qr(q[j].F.S)-qr(q[j].F.F-1);
            j++;
        }
    }
    for(int i=0;i<m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
