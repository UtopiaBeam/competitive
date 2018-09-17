#include<cstdio>
#include<vector>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int n,m,s,e,w,r[202],rs,re,g[202][202],cnt;
long long ans;
vector<P> v[2][10002];
int f(int x){
    if(x!=r[x])     r[x]=f(r[x]);
    return r[x];
}
int main(){
    scanf("%d %d",&n,&m);
    for(int t=0;t<m;t++){
        scanf("%d %d %d",&s,&e,&w);
        v[t&1][w].push_back(P(s,e));
        ans=0,cnt=n;
        for(int i=1;i<=n;i++)
            r[i]=i;
        for(int i=1;i<=10000;i++){
            v[!(t&1)][i].clear();
            for(int j=0;j<v[t&1][i].size();j++){
                rs=f(v[t&1][i][j].F),re=f(v[t&1][i][j].S);
                if(rs!=re){
                    ans+=i;
                    r[rs]=re;
                    cnt--;
                    v[!(t&1)][i].push_back(v[t&1][i][j]);
                }
                if(cnt==1)      break;
            }
            if(cnt==1)      break;
        }
        if(cnt==1)      printf("%lld\n",ans);
        else            printf("-1\n");
    }
    return 0;
}
