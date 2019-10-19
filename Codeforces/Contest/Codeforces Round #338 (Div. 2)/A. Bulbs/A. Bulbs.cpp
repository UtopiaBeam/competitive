#include<cstdio>
int n,m,t,a[102];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        while(t--){
            int b;
            scanf("%d",&b);
            a[b]=1;
        }
    }
    for(int i=1;i<=m;i++)
        if(!a[i]){
            printf("NO\n");     return 0;
        }
    printf("YES\n");
    return 0;
}
