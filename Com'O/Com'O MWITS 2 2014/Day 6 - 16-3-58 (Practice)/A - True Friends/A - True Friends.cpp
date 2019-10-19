#include<bits/stdc++.h>
using namespace std;
bool visited[105];
vector <int> adj[105],re[105];
stack <int> s;
int n,cnt;
void dfs(int now){
    visited[now]=true;
    for(int i=0;i<(int)adj[now].size();i++)
        if(!visited[adj[now][i]])   dfs(adj[now][i]);
    s.push(now);
}
void redfs(int now){
    visited[now]=false,s.pop();
    for(int i=0;i<(int)re[now].size();i++)
        if(visited[re[now][i]])     redfs(re[now][i]);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(visited,false,sizeof(visited)),cnt=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                char a;
                scanf(" %c",&a);
                if(a=='Y')  adj[i].push_back(j),re[j].push_back(i);
            }
        for(int i=1;i<=n;i++)
            if(!visited[i])     dfs(i);
        while(!s.empty())
            if(visited[s.top()]){
                redfs(s.top());     cnt++;
            }
        for(int i=1;i<=n;i++)
            adj[i].clear(),re[i].clear();
        printf("%d\n",cnt);
    }
    return 0;
}
