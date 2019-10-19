#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[105],a,b;
int n,m,dp[105][30][105],d[30][30],c,len,ans;
int main(){
    scanf(" %s %d %d",s,&m,&n);
    len=strlen(s);
    while(n--){
        scanf(" %c %c %d",&a,&b,&c);
        d[a-'a'][b-'a']=c;
    }
    for(int i=len-2;i>=0;i--)
        for(int j=0;j<26;j++)
            dp[i][j][0]=dp[i+1][s[i]-'a'][0]+d[j][s[i]-'a'];
    for(int i=len-2;i>=0;i--)
        for(int j=0;j<26;j++)
            for(int k=0;k<26;k++)
                for(int l=1;l<=m;l++)
                    dp[i][j][l]=max(dp[i][j][l],dp[i+1][k][l-(s[i]-'a'!=k)]+d[j][k]);
    for(int i=0;i<26;i++)
        for(int j=0;j<=m;j++)
            ans=max(ans,dp[0][i][j]);
    printf("%d\n",ans);
    return 0;
}
