#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int> adj[105][105];
int n,m,s,e,c,b[105];
bool dfs(int nw,int c){
    b[nw]=1;
    if(nw==e)       return true;
    bool chk=false;
    for(int i=1;i<=n;i++)
        for(int j=0;j<adj[nw][i].size();j++)
            if(!b[i] && adj[nw][i][j]==c)    chk=chk||dfs(i,c);
    return chk;
}
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %d",&s,&e,&c);
        adj[s][e].push_back(c),adj[e][s].push_back(c);
    }
    scanf("%d",&m);
    while(m--){
        int cnt=0;
        scanf("%d %d",&s,&e);
        for(int i=1;i<=100;i++){
            memset(b,0,sizeof(b));
            if(dfs(s,i))      cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
