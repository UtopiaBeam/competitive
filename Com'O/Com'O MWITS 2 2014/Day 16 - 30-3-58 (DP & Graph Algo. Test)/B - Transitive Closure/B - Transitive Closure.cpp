#include<cstdio>
int adj[505][505],n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&adj[i][j]);
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(adj[i][k] && adj[k][j])
                    adj[i][j]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d ",adj[i][j]);
        printf("\n");
    }
    return 0;
}
