#include<cstdio>
#include<cstring>
int q,n,m,t;
char a[102][102][2];
int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d",&t);
            for(int j=0;j<t;j++)
                scanf(" %s",a[i][j]);
        }
    }
}
