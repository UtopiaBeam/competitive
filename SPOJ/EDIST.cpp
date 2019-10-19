#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[2002][2002],n;
char a[2002],b[2002];
int main(){
    scanf("%d",&n);
    while(n--){
        scanf(" %s %s",a,b);
        int la=strlen(a),lb=strlen(b);
        for(int i=1;i<=la;i++)
            dp[i][0]=i;
        for(int i=1;i<=lb;i++)
            dp[0][i]=i;
        for(int i=1;i<=la;i++)
            for(int j=1;j<=lb;j++)
                if(a[i-1]==b[j-1])      dp[i][j]=dp[i-1][j-1];
                else        dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
        printf("%d\n",dp[la][lb]);
    }
}
