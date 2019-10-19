#include<cstdio>
int d[505][505],cnt[505][505],n,m;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            d[i][j]=1<<20;
    while(m--){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        d[u][v]=d[v][u]=w,cnt[v][u]=cnt[u][v]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(d[i][j]>d[i][k]+d[k][j]) d[i][j]=d[i][k]+d[k][j],cnt[i][j]=cnt[i][k]+cnt[k][j];
                else if(d[i][j]==d[i][k]+d[k][j])   cnt[i][j]+=cnt[i][k]+cnt[k][j];
            }
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            printf("%d ",cnt[i][j]);
    return 0;
}
