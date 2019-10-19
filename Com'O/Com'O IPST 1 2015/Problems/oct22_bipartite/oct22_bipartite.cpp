#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<int> G[100002];
int t,n,m,s,e,c[100002];
int main(){
    scanf("%d",&t);
    while(t--){
        bool chk=true;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)   G[i].clear(),c[i]=0;
        while(m--){
            scanf("%d %d",&s,&e);
            G[s].push_back(e);  G[e].push_back(s);
        }
        queue<int> q;
        q.push(1);  c[1]=1;
        while(!q.empty() && chk){
            int u=q.front();
            q.pop();
            for(int i=0;i<G[u].size() && chk;i++){
                if(c[G[u][i]]==c[u])    chk=false;
                if(c[G[u][i]]==0){
                    c[G[u][i]]=-c[u];   q.push(G[u][i]);
                }
            }
        }
        if(chk)     printf("yes\n");
        else        printf("no\n");
    }
    return 0;
}
