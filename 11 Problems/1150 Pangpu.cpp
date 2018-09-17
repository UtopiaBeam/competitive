#include<cstdio>
int n,t,dp[2][60002];
int f(int x){
    if(x>60000)     x-=60001;
    else if(x<0)    x+=60001;
    return x;
}
int main(){
    scanf("%d",&n);
    dp[0][30000]=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        for(int j=0;j<=60000;j++)
            dp[i%2][j]=0;
        for(int j=0;j<=60000;j++){
            if(dp[(i+1)%2][j]){
                dp[i%2][f(j+t)]=1;
                dp[i%2][j]=1;
            }
        }
    }
    for(int i=60000;i>=0;i--)
        if(dp[n%2][i]){
            printf("%d\n",i-30000);
            return 0;
        }
}
