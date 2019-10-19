#include<cstdio>
#include<algorithm>
using namespace std;
char ch;
int n,c,v,dp[100005][3][2],s=1,e;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %c %d",&ch,&v);
        if(ch=='R')     c=1;
        else    c=0;
        dp[i][0][c]=dp[i-1][0][c]+v;
        dp[i][0][1-c]=dp[i-1][0][1-c];
        dp[i][1][c]=max(dp[i-1][0][1-c],dp[i-1][1][c])+v;
        dp[i][1][1-c]=max(dp[i-1][0][c],dp[i-1][1][1-c]);
        dp[i][2][c]=max(dp[i-1][0][c],max(dp[i-1][1][1-c],dp[i-1][2][c]))+v;
        dp[i][2][1-c]=max(dp[i-1][0][1-c],max(dp[i-1][1][c],dp[i-1][2][1-c]));
    }
    if(dp[n][2][0]>dp[n][2][1])     printf("L %d ",dp[n][2][0]),c=0;
    else    printf("R %d ",dp[n][2][1]),c=1;
    for(int i=n;i>1;i--){
        if(!e){
            if(dp[i-1][1][1-c]>dp[i-1][2][c])   e=i;
        }
        else{
            if(dp[i-1][0][c]>dp[i-1][1][1-c]){
                s=i;    break;
            }
        }
    }
    printf("%d %d\n",s,e-1);
    return 0;
}
