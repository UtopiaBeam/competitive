#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 1e9
int n,t,d[302][302],g[302][302];
int main(){
    scanf("%d %d",&n,&t);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&d[i][j]);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(d[i][j]==d[i][k]+d[k][j]){
                    if(i!=k && j!=k)    g[i][j]=-1;
                    if(g[i][k]>=0)      g[i][k]=d[i][k];
                    if(g[k][j]>=0)      g[k][j]=d[k][j];
                }
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++)
            if(g[i][j]>0)   cnt++;
        if(cnt>2){
            printf("%d\n",i);
            if(t==2)    printf("%d\n",cnt);
            return 0;
        }
    }
}
