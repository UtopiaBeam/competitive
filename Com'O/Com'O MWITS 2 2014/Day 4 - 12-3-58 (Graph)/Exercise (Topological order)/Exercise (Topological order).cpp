#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
typedef pair<int,int> PII;
vector <int> adj[40010];
vector <int> topo;
stack <int> zero;
int n,m,t;
int deg[40010];     //in-degree,index
bool mark[40010];   //is visited?
bool DAG(){
    for(int i=1;i<=n;i++){
        queue <int> q;
        memset(mark,false,sizeof(mark));
        q.push(i);
        while(!q.empty()){
            int now=q.front();
            q.pop();
            mark[now]=true;
            for(int j=0;j<(int)adj[now].size();j++){
                if(adj[now][j]==i)      return false;
                if(!mark[adj[now][j]])  q.push(adj[now][j]);
            }
        }
    }
    return true;
}
int main(){
    scanf("%d",&t);
    while(t--){
        memset(deg,0,sizeof(deg));
        topo.clear();
        scanf("%d %d",&n,&m);
        while(m--){
            int str,end;
            scanf("%d %d",&str,&end);
            adj[str].push_back(end);
            deg[end]++;
        }
        if(!DAG())  printf("no topological order\n");
        else{
            for(int i=1;i<=n;i++)
                if(!deg[i])     zero.push(i);
            while(!zero.empty()){
                int now=zero.top();
                zero.pop();
                topo.push_back(now);
                for(int i=0;i<(int)adj[now].size();i++){
                    deg[adj[now][i]]--;
                    if(!deg[adj[now][i]])   zero.push(adj[now][i]);
                }
            }
            for(int i=0;i<(int)topo.size();i++)
                printf("%d ",topo[i]);
            printf("\n");
        }
        for(int i=1;i<=n;i++)
            adj[i].clear();
    }
    return 0;
}
