#include<cstdio>
#include<vector>
#include<queue>
#define L long long
#define P pair<L,int>
#define F first
#define S second
using namespace std;
vector<P> g[100002],tr;
priority_queue<P> q;
int n,m,k,s,e,cnt=0,in[100002];
L w,d[100002];
int main(){
    scanf("%d %d %d",&n,&m,&k);
    while(m--){
        scanf("%d %d %I64d",&s,&e,&w);
        g[s].push_back(P(w,e));
        g[e].push_back(P(w,s));
    }
    while(k--){
        scanf("%d %I64d",&e,&w);
        g[1].push_back(P(w,e));
        tr.push_back(P(w,e));
    }
    for(int i=1;i<=n;i++)
        d[i]=1e18;
    q.push(P(0,1));
    while(!q.empty()){
        s=q.top().S,w=-q.top().F;
        q.pop();
        if(d[s]>w){
            d[s]=w;
            for(int i=0;i<g[s].size();i++)
                if(w+g[s][i].F<d[g[s][i].S])
                    q.push(P(-w-g[s][i].F,g[s][i].S));
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<g[i].size();j++)
            if(d[i]+g[i][j].F==d[g[i][j].S])
                in[g[i][j].S]++;
    for(int i=0;i<tr.size();i++)
        if(tr[i].F!=d[tr[i].S] || in[tr[i].S]>1){
            cnt++;
            if(tr[i].F==d[tr[i].S])     in[tr[i].S]--;
        }
    printf("%d\n",cnt);
    return 0;
}
