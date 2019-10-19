#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define P pair<int,int>
#define PP pair<int,P>
#define F first
#define S second
#define INF 1e9
vector<PP> G[100002];
priority_queue<PP> H;
int n,m,k,s,e,w,d[100002][10],b[100002][10];
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
            d[i][j]=INF;
    while(m--){
        int t=0;
        scanf("%d %d %d",&s,&e,&w);
        if(w<-100)  t=1;
        if(w<0)     w=0;
        G[s].push_back(PP(t,P(e,w)));
    }
    H.push(PP(0,P(0,1)));
    while(!H.empty()){
        int w=-H.top().F,t=-H.top().S.F,u=H.top().S.S;
        H.pop();
        if(!b[u][t]){
            d[u][t]=w;  b[u][t]=1;
            for(int i=0;i<G[u].size();i++){
                PP v=G[u][i];
                if(v.F+t<=k && !b[v.S.F][v.F+t] && d[v.S.F][v.F+t]>w+v.S.S){
                    H.push(PP(-w-v.S.S,P(-v.F-t,v.S.F)));
                }
            }
        }
    }
    int mn=INF;
    for(int i=0;i<=k;i++)   mn=min(mn,d[n][i]);
    if(mn==INF)     printf("-1\n");
    else    printf("%d\n",mn);
    return 0;
}
