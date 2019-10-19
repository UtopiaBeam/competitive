#include<cstdio>
int T,n,k,x;
int main(){
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d %d",&n,&k);
        bool dp[2][100010]={};
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            for(int j=0;j<k;j++)
                dp[i&1][j]=false;
            dp[i&1][0]=true;
            for(int j=0;j<k;j++)
                dp[i&1][j]|=dp[!(i&1)][j];
            for(int j=0;j<k;j++)
                dp[i&1][(j+x)%k]|=dp[!(i&1)][j];
        }
        printf("Case #%d: ",t);
        for(int i=k-1;i>=0;i--)
            if(dp[n&1][i]){
                printf("%d\n",i);
                break;
            }
    }
    return 0;
}
