#include<cstdio>
int n,m,t;
int main(){
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d %d",&n,&m);
        int ans=0;
        for(int j=0;j<=m/20;j++){
            if(m-20*j>n)    continue;
            ans++;
        }
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
