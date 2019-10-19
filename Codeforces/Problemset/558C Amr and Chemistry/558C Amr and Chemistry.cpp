#include<cstdio>
#include<queue>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
queue<P> q;
int n,t,d,cnt[100005],a[100005],mark[100005],ans=1e9;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        q.push(P(t,0));
        while(!q.empty()){
            t=q.front().F,d=q.front().S;
            q.pop();
            if(mark[t]==i)      continue;
            mark[t]=i,a[t]+=d,cnt[t]++;
            if(t<<1<=100000 && mark[t<<1]!=n)   q.push(P(t<<1,d+1));
            if(t>>1>=1 && mark[t>>1]!=n)   q.push(P(t>>1,d+1));
        }
    }
    for(int i=0;i<=100000;i++)
        if(cnt[i]==n && ans>a[i])     ans=a[i];
    printf("%d\n",ans);
    return 0;
}
