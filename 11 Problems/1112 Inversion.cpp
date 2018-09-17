#include<cstdio>
#include<cstring>
int dp[10002],qs[2][10002];
int n,k;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<=k;i++)   qs[0][i]=1;
    for(int i=1;i<=n;i++){          //No. of elements
        dp[0]=qs[i&1][0]=1;          //0-inversion
        for(int j=1;j<=k;j++){      //No. of inversions
            dp[j]=(qs[!(i&1)][j]-(j-i>=0)*qs[!(i&1)][j-i])%2012;
            qs[i&1][j]=(dp[j]+qs[i&1][j-1])%2012;
        }
    }
    printf("%d\n",dp[k]);
    return 0;
}
