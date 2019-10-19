#include<cstdio>
#include<vector>
#include<queue>
#define INF 1<<20
using namespace std;
typedef pair <int,int> PII;
vector <PII> adj[5010];
priority_queue <PII> q;
int d[5010],n,m,mark[5010],str,end,w;
void dijs(){
    int t1,t2,i;
    while(!q.empty()){
        t1=(q.top()).first*(-1),t2=(q.top()).second;
        q.pop();
        if(!mark[t2]){
            d[t2]=t1,mark[t2]=1;
            for(i=0;i<(int)adj[t2].size();i++)
                if(mark[adj[t2][i].first]==0 && d[adj[t2][i].first]>d[t2]+adj[t2][i].second)
                    q.push(PII((-1)*(d[t2]+adj[t2][i].second),adj[t2][i].first));
        }
    }
}
int main(){
    int i;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        d[i]=INF,mark[i]=0;
    while(m--){
        scanf("%d %d %d",&str,&end,&w);
        adj[str].push_back(PII(end,w));
        adj[end].push_back(PII(str,w));
    }
    q.push(PII(0,1));
    dijs();
    printf("%d\n",d[n]);
    return 0;
}
