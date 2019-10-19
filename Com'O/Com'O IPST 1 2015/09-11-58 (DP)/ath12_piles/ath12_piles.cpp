#include<cstdio>
int a[102][102]={{1},{1,1}},dp[102][102],t,n,k;
int main(){
    for(int i=2;i<=100;i++){
        a[i][0]=a[i][i]=1;
        for(int j=1;j<i;j++){
            a[i][j]=a[i-1][j-1]+a[i-1][j];
            a[i][j]%=9871;
        }
    }
    for(int i=1;i<=100;i++)
        dp[0][i]=1;
    for(int i=1;i<=100;i++)
        for(int j=1;j<=i;j++){
            int sum=0;
            for(int k=j;k<=i;k++){
                dp[i][j]+=a[i][k]*dp[i-k][j];
                dp[i][j]%=9871;
            }
        }
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        printf("%d\n",dp[n][k]);
    }
    return 0;
}
