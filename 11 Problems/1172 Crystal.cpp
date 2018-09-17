#include<stdio.h>
int n,dp[2002]={1};
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            dp[i+1]+=dp[j]*dp[i-j],dp[i+1]%=10001;
    printf("%d\n",dp[n]);
    return 0;
}
