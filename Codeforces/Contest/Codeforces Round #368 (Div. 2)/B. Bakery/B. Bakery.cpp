#include<cstdio>
#include<vector>
#include<algorithm>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
vector<P> g[100002];
int n,m,k,s,e,w,a[100002],mn=1<<30;
int main(){
    scanf("%d %d %d",&n,&m,&k);
    while(m--){
        scanf("%d %d %d",&s,&e,&w);
        g[s].push_back(P(e,w));
        g[e].push_back(P(s,w));
    }
    while(k--){
        scanf("%d",&s);
        a[s]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<g[i].size();j++)
            if(a[g[i][j].F]-a[i])
                mn=min(mn,g[i][j].S);
    }
    if(mn==1<<30)       printf("-1\n");
    else            printf("%d\n",mn);
    return 0;
}
