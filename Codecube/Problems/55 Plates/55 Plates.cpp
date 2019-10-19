#include<cstdio>
#define MOD 9871
int q,n,m,dp[1002][1002];
int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
