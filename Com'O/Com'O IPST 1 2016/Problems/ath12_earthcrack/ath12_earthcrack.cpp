#include<cstdio>
#include<algorithm>
using namespace std;
int t,r,c,a[502][502],dp[502][502];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&r,&c);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                scanf("%d",&a[i][j]);
        for(int j=0;j<c;j++)    dp[0][j]=a[0][j];
        for(int i=1;i<r;i++)
            for(int j=0;j<c;j++)
                dp[i][j]=(int)1e9;
        for(int i=0;i<r-1;i++){
            for(int j=0;j<c;j++){
                if(j>0)     dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]+a[i+1][j-1]);
                if(j<c-1)   dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+a[i+1][j+1]);
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a[i+1][j]);
            }
        }
        int mn=(int)1e9;
        for(int j=0;j<c;j++)    mn=min(mn,dp[r-1][j]);
        printf("%d\n",mn);
    }
    return 0;
}
