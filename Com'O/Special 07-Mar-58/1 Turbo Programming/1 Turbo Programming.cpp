//Dijkstra's algorithm
#include<cstdio>
#include<vector>
#include<queue>
#define INF 1<<20
using namespace std;
typedef pair<int,int> PII;
vector <PII> adj[1010];
priority_queue <PII> que;
int n,m,q,d[1010],isrelax[1010];
void dijs(){
    while(!que.empty()){
        int w=(que.top()).first,end=(que.top()).second;
        w*=-1;
        que.pop();
        if(!isrelax[end]){
            d[end]=w,isrelax[end]=1;
            for(int i=0;i<(int)adj[end].size();i++){
                if(!isrelax[adj[end][i].first] && d[adj[end][i].first]>d[end]+adj[end][i].second)
                    que.push(PII(-1*(d[end]+adj[end][i].second),adj[end][i].first));
            }
        }
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=n;i++)
        d[i]=INF,isrelax[i]=0;
    while(m--){
        int str,end,w;
        scanf("%d %d %d",&str,&end,&w);
        adj[str].push_back(PII(end,w));
    }
    que.push(PII(0,1));    //Distance,EndNode
    dijs();
    while(q--){
        int x;
        scanf("%d",&x);
        if(isrelax[x])  printf("%d\n",d[x]);
        else    printf("-1\n");
    }
    return 0;
}
