#include<cstdio>
#include<queue>
#include<vector>
#define Pi pair<int,int>
#define Pl pair<long long,int>
#define P pair<Pl,Pi>
#define F first
#define S second
using namespace std;
int n,m,s,e,in,nw=0,r[200002];
long long w,a[200002],sum=0;
vector<int> g[200002],v;
priority_queue<P> q[3],mst;
int findr(int u){
    if(u!=r[u])     r[u]=findr(r[u]);
    return r[u];
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)   r[i]=i;
    for(int i=0;i<m;i++){
        scanf("%d %d %I64d",&s,&e,&w);
        q[nw].push(P(Pl(-w,i),Pi(s,e)));
        g[s].push_back(e);
        g[e].push_back(s);
    }
    while(true){
//        printf("#\n");
        if(q[nw].empty())       break;
        v.clear();
        while(!q[nw].empty()){
            w=-q[nw].top().F.F,in=q[nw].top().F.S,s=q[nw].top().S.F,e=q[nw].top().S.S;
            q[nw].pop();
//            printf("s = %d, e = %d\n",s,e);
            int rs=findr(s),re=findr(e);
            if(rs!=re){
                sum+=w,r[s]=re,v.push_back(in);
                mst.push(P(Pl(w,in),Pi(s,e)));
            }
            else    q[1-nw].push(P(Pl(-w,in),Pi(s,e)));
        }
        for(int i=0;i<v.size();i++)
            if(!a[v[i]])    a[v[i]]=sum;
//        printf("*\n");
        if(mst.empty())     break;
        w=mst.top().F.F,s=mst.top().S.F,e=mst.top().S.S;
        mst.pop();
        sum-=w;
//        for(int i=1;i<=n;i++)
//            printf("%d ",r[i]);
//        printf("\n");
        for(int i=0;i<g[s].size();i++)
            if(g[s][i]!=e){
                r[s]=g[s][i];       break;
            }
        for(int i=0;i<g[e].size();i++)
            if(g[e][i]!=s){
                r[e]=g[e][i];       break;
            }
        nw=1-nw;
    }
    for(int i=0;i<m;i++)
        printf("%I64d\n",a[i]);
    return 0;
}
