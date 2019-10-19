#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
int dp[102][102];
char a[102],b[102];
stack<char> s;
int main(){
    while(scanf(" %s %s",a,b)!=EOF){
        int la=strlen(a),lb=strlen(b);
        for(int i=1;i<=la;i++)
            dp[i][0]=i;
        for(int i=1;i<=lb;i++)
            dp[0][i]=i;
        for(int i=1;i<=la;i++)
            for(int j=1;j<=lb;j++)
                if(a[i-1]==b[j-1])      dp[i][j]=dp[i-1][j-1]+1;
                else    dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
        //Backtrack
    }
    return 0;
}
