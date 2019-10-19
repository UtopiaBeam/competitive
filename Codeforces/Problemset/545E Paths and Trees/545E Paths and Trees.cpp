#include<cstdio>
#include<vector>
#include<queue>
#define L long long
#define Pi pair<int,int>
#define Pl pair<L,int>
#define PI pair<Pl,int>
#define F first
#define S second
using namespace std;
vector<PI> g[300002];
priority_queue<Pl> q;
int n,m,s,e;
L d[300002],w,h[300002];
bool a[300002]={};
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        d[i]=-1;
    for(int i=1;i<=m;i++){
        scanf("%d %d %I64d",&s,&e,&w);
        g[s].push_back(PI(Pl(w,e),i));
        g[e].push_back(PI(Pl(w,s),i));
        h[i]=w;
    }
    scanf("%d",&s);
    d[s]=0;
    q.push(Pl(0,s));
    while(!q.empty()){
        w=-q.top().F,s=q.top().S;
        q.pop();
        for(int i=0;i<g[s].size();i++){
            e=g[s][i].F.S;
            if(d[e]<0 || d[e]>=w+g[s][i].F.F){
                if(d[e]!=w+g[s][i].F.F)      q.push(Pl(-w-g[s][i].F.F,e));
                d[e]=w+g[s][i].F.F;
                for(int j=0;j<g[e].size();j++)
                    if(d[e]<=d[g[e][j].F.S]+g[e][j].F.F && a[g[e][j].S] && g[e][j].F.F>=g[s][i].F.F)
                        a[g[e][j].S]=false;
                a[g[s][i].S]=true;
            }
        }
    }
    w=0;
    for(int i=1;i<=m;i++)
        if(a[i])    w+=h[i];
    printf("%I64d\n",w);
    for(int i=1;i<=m;i++)
        if(a[i])    printf("%d ",i);
    return 0;
}
