#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX (int)-2e9
using namespace std;
char s[105],a,b;
int n,m,dp[105][105][30],d[30][30],c,ans=MAX;
int main(){
    scanf(" %s %d %d",s,&m,&n);
    while(n--){
        scanf(" %c %c %d",&a,&b,&c);
        d[a-'a'][b-'a']=c;
    }
    n=strlen(s);
    for(int i=0;i<105;i++)
        for(int j=0;j<105;j++)
            for(int k=0;k<26;k++)
                dp[i][j][k]=MAX;
    for(int i=0;i<26;i++)
        dp[0][s[0]-'a'!=i][i]=0;
    for(int i=1;i<n;i++)
        for(int t=0;t<=m;t++)
            for(int j=0;j<26;j++){
                int tmp=MAX;
                for(int k=0;k<26;k++)
                    if(t-(j!=s[i]-'a')>=0)
                        tmp=max(tmp,dp[i-1][t-(j!=s[i]-'a')][k]+d[k][j]);
                dp[i][t][j]=tmp;
            }
    for(int i=0;i<=m;i++)
        for(int j=0;j<26;j++)
            ans=max(ans,dp[n-1][i][j]);
    printf("%d\n",ans);
    return 0;
}
