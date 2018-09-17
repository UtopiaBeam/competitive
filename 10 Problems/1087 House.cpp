#include<cstdio>
#include<algorithm>
#define chk 1-2*((i+j)%2)
using namespace std;
int a[305][305],dp[305][305][2],r,c,k,Max=0;  //0 = right, 1 = down
int main(){
    scanf("%d %d %d",&r,&c,&k);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++){
            scanf("%d",&a[i][j]);
            a[i][j]*=chk,dp[i][j][1]=dp[i][j][0]=a[i][j];
        }
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            dp[i][j][0]+=dp[i][j-1][0],dp[i][j][1]+=dp[i-1][j][1];
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++){
            int sum=0;
            if(i+k<r)   sum+=dp[i+k][j][1];
            else    sum+=dp[r][j][1];
            if(j+k<c)   sum+=dp[i][j+k][0];
            else    sum+=dp[i][c][0];
            if(i-k>0)   sum-=dp[i-k-1][j][1];
            if(j-k>0)   sum-=dp[i][j-k-1][0];
            sum-=a[i][j],sum*=chk;
            if(Max<sum) Max=sum;
        }
    printf("%d\n",Max);
    return 0;
}
