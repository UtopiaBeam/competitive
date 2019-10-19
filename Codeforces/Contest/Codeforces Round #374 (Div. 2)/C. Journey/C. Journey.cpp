#include<cstdio>
#include<vector>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int n,m,s,e,w,t,dp[5002][5002],p[5002][5002],ans[5002];
vector<P> g[5002];
int main(){
    scanf("%d %d %d",&n,&m,&t);
    while(m--){
        scanf("%d %d %d",&s,&e,&w);
        g[s].push_back(P(e,w));
    }
    return 0;
}
