#include<cstdio>
#include<algorithm>
#include<queue>
#define P pair<int,int>
#define PP pair<int,P>
#define F first
#define S second
using namespace std;
int n,r[302],g[302][302],w,s,e,t;
priority_queue<PP> q;
int fr(int x){
    if(x==r[x])     return r[x];
    return r[x]=fr(r[x]);
}
int main(){
    scanf("%d %d",&n,&t);
    for(int i=1;i<=n;i++){
        r[i]=i;
        for(int j=1;j<=n;j++){
            scanf("%d",&w);
            if(i<j)     q.push(PP(-w,P(i,j)));
        }
    }
    while(!q.empty()){
        w=-q.top().F,s=q.top().S.F,e=q.top().S.S;
        q.pop();
        int rs=fr(s),re=fr(e);
        if(rs==re)  continue;
        g[s][e]=g[e][s]=w;
        r[rs]=re;
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++)
            cnt+=(g[i][j]>0);
        if(cnt>=3){
            printf("%d\n",i);
            if(t==2)    printf("%d\n",cnt);
            return 0;
        }
    }
}
