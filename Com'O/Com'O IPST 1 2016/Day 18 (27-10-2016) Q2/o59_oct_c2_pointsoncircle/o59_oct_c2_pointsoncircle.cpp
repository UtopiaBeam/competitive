#include<cstdio>
#include<queue>
#include<vector>
#define P pair<int,int>
#define PP pair<int,P>
#define F first
#define S second
using namespace std;
priority_queue<PP> q;
vector<P> g[1002];
int r[1002],num[1002];
int n,m,w,s,e,rs,re;
int fr(int x){
    if(x==r[x])     return r[x];
    return r[x]=fr(r[x]);
}
int main(){
    scanf("%d %d",&m,&n);
    for(int i=1;i<=n;i++){
        r[i]=i;     num[i]=-1;
        for(int j=1;j<=n;j++){
            scanf("%d",&w);
            if(i!=j)    q.push(PP(-w,P(i,j)));
        }
    }
    while(!q.empty()){
        w=-q.top().F,s=q.top().S.F,e=q.top().S.S;
        q.pop();
        rs=fr(s);   re=fr(e);
        if(rs==re)      continue;
        r[rs]=re;
        g[s].push_back(P(e,w));
        g[e].push_back(P(s,w));
    }
    for(int i=1;i<=n;i++)
        if(g[i].size()==1){
            s=i;
            break;
        }
    w=0;
    while(true){
        int chk=1;
        num[s]=w;
        for(int i=0;i<g[s].size();i++)
            if(num[g[s][i].F]<0){
                w=(w+g[s][i].S)%m;
                s=g[s][i].F;
                chk=0;
                break;
            }
        if(chk)     break;
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",num[i]);
    return 0;
}
