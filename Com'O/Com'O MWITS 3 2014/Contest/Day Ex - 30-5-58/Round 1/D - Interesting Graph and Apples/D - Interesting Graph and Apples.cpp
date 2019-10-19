#include<cstdio>
int adj[55][55],deg[55],c[55],n,m,cnt=1,chk[55];
void dfs(int i){
    chk[i]=1,c[i]=cnt;
    for(int j=1;j<=n;j++)
        if(adj[i][j] && !chk[j])    dfs(j);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int s,e;
        scanf("%d %d",&s,&e);
        adj[s][e]=adj[e][s]=1;
        deg[s]++,deg[e]++;
    }
    for(int i=1;i<=n;i++)
        if(!chk[i])     dfs(i),cnt++;
    if(n==1)    printf("YES\n1\n1 1\n");
    else{
        for(int i=1;i<=n;i++){
            if(c[i]!=cnt-1 || deg[i]!=2)
                break;
            if(i==n){
                printf("YES\n0\n");     return 0;
            }
        }
        if(m>=n){
            printf("NO\n");     return 0;
        }
        for(int i=1;i<=n;i++)
            if(deg[i]>2){
                printf("NO\n");     return 0;
            }
        printf("YES\n%d\n",n-m);
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                if(deg[i]<2 && deg[j]<2 && !adj[i][j])
                    printf("%d %d\n",i,j);
    }
    return 0;
}
