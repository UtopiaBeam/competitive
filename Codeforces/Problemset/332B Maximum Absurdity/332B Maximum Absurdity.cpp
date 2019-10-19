#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,p[200002][3];
long long a[200002],dp[200002][3],qs[200002];
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%I64d",a+i);
    dp[n][1]=dp[n][2]=-1<<30;
    for(int i=n-1;i>=0;i--){
        qs[i]=qs[i+1]+a[i];
        dp[i][0]=dp[i+1][0];
        if(i+k<=n){
            dp[i][1]=max(dp[i+1][1],dp[i+k][0]+qs[i]-qs[i+k]);
            if(dp[i][1]==dp[i+k][0]+qs[i]-qs[i+k])    p[i][1]=1;
            else        p[i][1]=0;
        }
        if(i+2*k<=n){
            dp[i][2]=max(dp[i+1][2],dp[i+k][1]+qs[i]-qs[i+k]);
            if(dp[i][2]==dp[i+k][1]+qs[i]-qs[i+k])    p[i][2]=1;
            else        p[i][2]=0;
        }
    }
    int x=0,y=2;
    while(y){
        if(p[x][y]){
            printf("%d ",x+1);
            x+=k,y--;
        }
        else    x++;
    }
    return 0;
}
