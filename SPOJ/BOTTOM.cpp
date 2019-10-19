#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;
vector<int> g[5002],rg[5002];
int n,m,u,v,d[5002],scc[5002];
int main(){
    while(scanf("%d",&n) && n){
        scanf("%d",&m);
        while(m--){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            rg[v].push_back(u);
            d[v]++;
        }
    }
    return 0;
}
