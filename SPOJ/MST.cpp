#include<cstdio>
#include<queue>
#define P pair<int,int>
#define PP pair<long long,P>
#define F first
#define S second
using namespace std;
priority_queue<PP> q;
int n,m,s,e,w,r[10002];
long long sum=0;
int find(int u){
    if(r[u]!=u)     r[u]=find(r[u]);
    return r[u];
}
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %lld",&s,&e,&w);
        q.push(PP(-w,P(s,e)));
    }
    for(int i=1;i<=n;i++)
        r[i]=i;
    while(!q.empty()){
        w=-q.top().F,s=q.top().S.F,e=q.top().S.S;
        q.pop();
        int rs=find(s),re=find(e);
        if(rs!=re)      r[rs]=re,sum+=w;
    }
    printf("%lld\n",sum);
    return 0;
}
