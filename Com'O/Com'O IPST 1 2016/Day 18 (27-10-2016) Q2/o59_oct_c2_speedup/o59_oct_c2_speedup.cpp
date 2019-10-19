#include<cstdio>
#include<vector>
#include<queue>
#define L long long
#define P pair<int,L>
#define F first
#define S second
#define INF (L)1<<60
using namespace std;
struct St{
    int node;
    L dist;
    int lastDrink,totalDrink;
    St(int node=0,L dist=0,int lastDrink=0,int totalDrink=0):
        node(node),dist(dist),lastDrink(lastDrink),totalDrink(totalDrink){}
    bool operator<(const St &x)const{
        return dist > x.dist;
    }
}nw;
priority_queue<St> q;
vector<P> g[80002];
int n,m,k,l,isDrink[80002],s,e;
L d[80002][10],w;
int main(){
    scanf("%d %d %d %d",&n,&m,&l,&k);
    while(m--){
        scanf("%d %d %lld",&s,&e,&w);
        g[s].push_back(P(e,w));
    }
    while(l--){
        scanf("%d",&s);
        isDrink[s]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
            d[i][j]=INF;
    q.push(St(1,0,0,0));
    while(!q.empty()){
        nw=q.top();
        q.pop();
        if(d[nw.node][nw.totalDrink]<=nw.dist)
            continue;
        d[nw.node][nw.totalDrink]=nw.dist;
        for(int i=0;i<g[nw.node].size();i++){
            if(d[g[nw.node][i].F][nw.totalDrink]>nw.dist+g[nw.node][i].S/(1<<nw.totalDrink))
                q.push(St(g[nw.node][i].F,nw.dist+g[nw.node][i].S/(1<<nw.totalDrink),nw.lastDrink,nw.totalDrink));
            if(isDrink[nw.node] && nw.node!=nw.lastDrink){
                if(nw.totalDrink<k && d[g[nw.node][i].F][nw.totalDrink+1]>nw.dist+g[nw.node][i].S/(1<<(nw.totalDrink+1)))
                    q.push(St(g[nw.node][i].F,nw.dist+g[nw.node][i].S/(1<<(nw.totalDrink+1)),nw.node,nw.totalDrink+1));
            }
        }
    }
    printf("%lld\n",d[n][k]);
    return 0;
}
