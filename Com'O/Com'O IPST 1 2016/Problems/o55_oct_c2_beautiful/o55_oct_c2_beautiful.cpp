#include<cstdio>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#define MAXN (1<<N)
#define P pair<int,int>
#define F first
#define S second
using namespace std;
vector<int> g[10002],v;
unordered_map<int,int> mp;
queue<P> q;
int n,m,w,deg[10002],d[10002],s,e,N=0,dp[(1<<16)+2],ng[20][20];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&s,&e);
        g[s].push_back(e);
        g[e].push_back(s);
        deg[s]++;   deg[e]++;
    }
    for(int i=1;i<=n;i++){
        if(deg[i]&1){
            v.push_back(i);
            mp[i]=++N;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=1;j<=n;j++)
            d[j]=1<<30;
        q.push(P(v[i],0));
        while(!q.empty()){
            s=q.front().F,w=q.front().S;
            q.pop();
            if(d[s]<=w)     continue;
            d[s]=w;
            if(mp[s]>0)     ng[mp[v[i]]][mp[s]]=w;
            for(int j=0;j<g[s].size();j++)
                if(d[g[s][j]]>d[s]+1)
                    q.push(P(g[s][j],d[s]+1));
        }
    }
    for(int k=1;k<=N;k++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                ng[i][j]=min(ng[i][j],ng[i][k]+ng[k][j]);
    for(int i=0;i<MAXN;i++){
        int cnt=0;
        for(int j=i;j;j>>=1)
            cnt+=j&1;
        if(cnt&1)   continue;
        if(i)   dp[i]=1<<30;
        for(int j=0;1<<j<=i;j++)
            for(int k=j+1;1<<k<=i;k++)
                if((i>>j)&1 && (i>>k)&1)
                    dp[i]=min(dp[i],dp[i-(1<<j)-(1<<k)]+ng[j+1][k+1]);
    }
    printf("%d\n",m-dp[MAXN-1]);
    return 0;
}
