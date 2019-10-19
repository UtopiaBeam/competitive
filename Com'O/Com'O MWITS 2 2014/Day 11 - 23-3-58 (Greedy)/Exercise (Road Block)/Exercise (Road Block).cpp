#include<cstdio>
#include<vector>
#include<queue>
#define INF 1<<20
using namespace std;
typedef pair <int,int> PII;
vector <PII> adj[5005];
vector <int> path;
priority_queue <PII> q;
int d[5005],mark[5005],pre[5005];
void dijs(){
    while(!q.empty()){
        int w=(-1)*(q.top()).first,now=(q.top()).second;
        q.pop();
        if(!mark[now]){
            mark[now]=1,d[now]=w;
            for(int i=0;i<(int)adj[now].size();i++)
                if(!mark[adj[now][i].first] && d[adj[now][i].first]>=d[now]+adj[now][i].second)
                    q.push(PII((-1)*(d[now]+adj[now][i].second),adj[now][i].first)),pre[adj[now][i].first]=now;
        }
    }
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        d[i]=INF;
    while(m--){
        int str,end,w;
        scanf("%d %d %d",&str,&end,&w);
        adj[str].push_back(PII(end,w)),adj[end].push_back(PII(str,w));
    }
    q.push(PII(0,1));
    dijs();
    int now=n;
    while(1){
        path.push_back(now);
        if(now==1)      break;
        now=pre[now];
    }
    int dif=0,dis=d[n];
    for(int i=1;i<path.size();i++){
        for(int j=1;j<=n;j++)
            d[j]=INF,mark[j]=0;
        for(int j=0;j<(int)adj[path[i]].size();j++)
            if(adj[path[i]][j].first==path[i-1]){
                adj[path[i]][j].second*=2;      break;
            }
        for(int j=0;j<(int)adj[path[i-1]].size();j++)
            if(adj[path[i-1]][j].first==path[i]){
                adj[path[i-1]][j].second*=2;    break;
            }
        q.push(PII(0,1));
        dijs();
        if(dif<d[n]-dis)    dif=d[n]-dis;
        for(int j=0;j<(int)adj[path[i]].size();j++)
            if(adj[path[i]][j].first==path[i-1]){
                adj[path[i]][j].second/=2;      break;
            }
        for(int j=0;j<(int)adj[path[i-1]].size();j++)
            if(adj[path[i-1]][j].first==path[i]){
                adj[path[i-1]][j].second/=2;    break;
            }
    }
    printf("%d\n",dif);
    return 0;
}
