#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define L long long
#define P pair<L,int>
#define PP pair<P,int>
#define F first
#define S second
using namespace std;
int n,m,a,b,s,e,r[10002];
L w,mn=1LL;
priority_queue<PP> q;
vector<PP> g[3002];
vector<int> v;
void f(int s,int e){
    for(int i=1;i<=m;i++)   r[i]=0;
    q.push(PP(P(0,s),0));
    for(int i=0;i<g[s].size();i++)
        r[g[s][i].S]=-1;
    L sum=0;
    int cnt=1;
    while(!q.empty()){
        w=q.top().F.F;
        int u=q.top().F.S,in=q.top().S;
        q.pop();
        r[in]=1;    cnt--;
        sum-=w;
        for(int i=0;i<g[u].size();i++){
            int id=g[u][i].S;
            if(r[id]==0){
                r[id]=-1;       cnt++;
                sum+=g[u][i].F.F;
            }
        }
        if(cnt<=2 && sum<mn){
            v.clear();
            for(int i=1;i<=m;i++)
                if(r[i]==-1)    v.push_back(i);
        }
    }
}
int main(){
    scanf("%d %d %d %d",&n,&m,&a,&b);
    for(int i=1;i<=m;i++){
        scanf("%d %d %I64d",&s,&e,&w);
        g[s].push_back(PP(P(w,e),i));
        g[e].push_back(PP(P(w,s),i));
    }
    f(a,b);     f(b,a);
    if(v.empty())   printf("-1\n");
    else{
        printf("%I64d\n%d\n",mn,v.size());
        for(int i=0;i<v.size();i++)
            printf("%d ",v[i]);
        printf("\n");
    }
    return 0;
}
