#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> PII;  //Weight,Node
vector <PII> adj[5010];
priority_queue <PII> q;
int isrelax[5010],d[5010][110],n,m,k;
void dijs(){
    while(!q.empty()){
        int w=(q.top()).first*(-1),now=(q.top()).second;
        q.pop();
        if(!isrelax[now]){
            d[now][0]=w,isrelax[now]=1;
            for(int i=0;i<(int)adj[now].size();i++){
                if(!isrelax[adj[now][i].second] && d[now][0]+adj[now][i].first<d[adj[now][i].second][0])
                    q.push(PII((-1)*(d[now][0]+adj[now][i].first),adj[now][i].second));
            }
        }
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        isrelax[i]=0;
        for(int j=0;j<=k;j++)
            d[i][j]=1<<20;
    }
    while(m--){
        int str,end,w;
        scanf("%d %d %d",&str,&end,&w);
        adj[str].push_back(PII(w,end));
    }
    q.push(PII(0,1));
    dijs();
    printf("%d\n%d\n%d\n",d[n][0],d[n][k],d[n][k]-d[n][0]);
    return 0;
}
