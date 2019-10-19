#include<cstdio>
#include<queue>
#include<vector>
#define INF 1<<20
using namespace std;
typedef pair<int,int> PII;
int d[1010],n,m,k,isrelax[1010],str,end,w;
vector <PII> adj[1010];
priority_queue <PII> q;
void dijs(){
    int t1,t2,i;
    while(!q.empty()){
        t1=(q.top()).first;
        t2=(q.top()).second;
        t1*=(-1);
        q.pop();
        if(isrelax[t2]==0){
            d[t2]=t1,isrelax[t2]=1;
            for(i=0;i<(int)adj[t2].size();i++){
                if(isrelax[adj[t2][i].first]==0 && d[adj[t2][i].first]>d[t2]+adj[t2][i].second)
                    q.push(PII((-1)*(d[t2]+adj[t2][i].second),adj[t2][i].first));
            }
        }
    }
}
int main(){
    int i;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++)
        d[i]=INF,isrelax[i]=0;
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&str,&end,&w);
        adj[str].push_back(PII(end,w));
    }
    q.push(PII(0,1));   //Enqueue (Distance,EndNode)
    dijs();
    while(k--){
        scanf("%d",&str);
        if(isrelax[str])    printf("%d\n",d[str]);
        else    printf("-1\n");
    }
    return 0;
}
