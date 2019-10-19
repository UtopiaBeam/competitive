#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PCD;
vector <PII> adj[60];   //Index,Weight
queue <PCD> q;  //Weight,<Index,State>
int n,rs,cs,re,ce,rx,cx,a[60][60],mark[60][60][2],Min=1<<20;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]<0)   a[i][j]*=-1,rx=i,cx=j;
        }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>1)     adj[(i-1)*n+j].push_back(PII((i-2)*n+j,a[i][j]));
            if(i<n)     adj[(i-1)*n+j].push_back(PII((i)*n+j,a[i][j]));
            if(j>1)     adj[(i-1)*n+j].push_back(PII((i-1)*n+j-1,a[i][j]));
            if(j<n)     adj[(i-1)*n+j].push_back(PII((i-1)*n+j+1,a[i][j]));
        }
    }
    scanf("%d %d %d %d",&rs,&cs,&re,&ce);
    q.push(PCD(0,PII((rs-1)*n+cs,0)));
    while(!q.empty()){
        int w=(q.front()).first,inx=(((q.front()).second).first-1)/n+1,iny=(((q.front()).second).first-1)%n+1,state=((q.front()).second).second;
        q.pop();
        if(!mark[inx][iny][state]){
            mark[inx][iny][state]=1;
            if(inx==re && iny==ce && state)
                if(Min>w)   Min=w;
            if(inx==rx && iny==cx)  state=1;
            for(int i=0;i<(int)adj[(inx-1)*n+iny].size();i++)
                q.push(PCD(w+a[(adj[(inx-1)*n+iny][i].first-1)/n+1][(adj[(inx-1)*n+iny][i].first-1)%n+1],PII(adj[(inx-1)*n+iny][i].first,state)));
        }
    }
    printf("%d\n",Min);
    return 0;
}
