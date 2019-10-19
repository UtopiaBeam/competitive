#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
#define P pair<int,int>
#define PP pair<int,P>
#define F first
#define S second
#define INF (int)1e9
int N,M,s[5002],e[5002],w[5002],mn;
int d[1002][2];
int dijk(int n){
    vector<P> G[1002];
    for(int i=0;i<n;i++){
        G[s[i]].push_back(P(e[i],w[i]));
        G[e[i]].push_back(P(s[i],w[i]));
    }
    for(int i=1;i<=N;i++)   d[i][0]=d[i][1]=INF;
    priority_queue<PP> q;
    q.push(PP(0,P(1,1)));
    while(!q.empty()){
        int t=-q.top().F,u=q.top().S.F,cnt=q.top().S.S;
        q.pop();
        if(d[u][cnt%2]<=t)      continue;
        d[u][cnt%2]=t;
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i].F,uv=G[u][i].S;
            if(d[v][(cnt+1)%2]>t+uv)
                q.push(PP(-t-uv,P(v,cnt+1)));
        }
    }
    return d[N][0];
}
int bs(int s,int e){
    if(s==e)    return s;
    int m=(s+e)/2;
    if(dijk(m)>mn)  return bs(m+1,e);
    return bs(s,m);
}
int main(){
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++)
        scanf("%d %d %d",&s[i],&e[i],&w[i]);
    mn=dijk(M);
    printf("%d %d\n",bs(1,M),mn);
    return 0;
}
