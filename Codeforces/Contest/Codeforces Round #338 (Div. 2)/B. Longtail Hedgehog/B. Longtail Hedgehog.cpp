#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> G[100002];
int n,m,s,e;
long long l[100002],mx=0;
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&s,&e);
        G[s].push_back(e);
        G[e].push_back(s);
    }
    for(int v=1;v<=n;v++){
        l[v]=1;
        for(auto u:G[v])
            if(u<v)     l[v]=max(l[v],l[u]+1);
        mx=max(mx,l[v]*(long long)G[v].size());
    }
    printf("%I64d\n",mx);
    return 0;
}
