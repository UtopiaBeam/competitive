#include<cstdio>
#include<cstring>
#include<algorithm>
char a[1002];
int dp[1002][2];    //0 = tolower, 1 = toupper
int main(){
    while(scanf(" %s",a)!=EOF){
        int len=strlen(a);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=len;i++){
            if(a[i-1]>='A' && a[i-1]<='Z')
                dp[i][0]=dp[i-1][1]+1;
            else    dp[i][0]=dp[i-1][1];
            if(a[i-1]>='a' && a[i-1]<='z')
                dp[i][1]=dp[i-1][0]+1;
            else    dp[i][1]=dp[i-1][0];
        }
        printf("%d\n",std::min(dp[len][0],dp[len][1]));
    }
    return 0;
}
