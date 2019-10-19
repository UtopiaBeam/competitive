#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
vector<int> G[100002];
stack<int> S;
int n,m,s,e,chk[100002];
void dfs(int u){
    chk[u]=1;
    for(int i=0;i<G[u].size();i++)
        if(!chk[G[u][i]])   dfs(G[u][i]);
    S.push(u);
}
bool DAG(){
    for(int i=1;i<=n;i++){
        queue<int> Q;
        Q.push(i);
        while(!Q.empty()){
            int u=Q.front();
            Q.pop();
            chk[u]=true;
            for(int j=0;j<(int)G[u].size();j++){
                if(G[u][j]==i)      return false;
                if(!chk[G[u][j]])  Q.push(G[u][j]);
            }
        }
    }
    return true;
}
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&s,&e);
        G[s].push_back(e);
    }
    if(!DAG()){
        printf("no\n");     return 0;
    }
    memset(chk,0,sizeof(chk));
    for(int i=1;i<=n;i++)
        if(!chk[i])   dfs(i);
    while(!S.empty()){
        printf("%d\n",S.top());
        S.pop();
    }
    return 0;
}
