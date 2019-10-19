#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
vector<pii> adj[100005];
vector<int> ans;
int n,x,y,t,mark[100005],cnt=0,tmp,b[100005];
int dfs(int now){
    if(mark[now])      return 0;
    mark[now]=1;
    int cnt=0;
    for(int i=0;i<adj[now].size();i++){
        if(adj[now][i].second==2)
            ;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d %d",&x,&y,&t);
        adj[x].push_back(pii(y,t)),adj[y].push_back(pii(x,t));
        if(t==2)    cnt++;
    }
    dfs(1);

    return 0;
}
