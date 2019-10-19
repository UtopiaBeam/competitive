#include<cstdio>
int n,dp[1005][1005];
char a[1005];
int pair(int str,int end){
    if(str>=end || dp[str][end])    return dp[str][end];
    if(a[str]==a[end])      return dp[str][end]=1+pair(str+1,end-1);
    int max=-10;
    for(int i=str;i<end;i++){
        int tmp;
        if(dp[str][i])  tmp=dp[str][i];
        else    tmp=pair(str,i);
        if(dp[i+1][end])    tmp+=dp[i+1][end];
        else    tmp+=pair(i+1,end);
        if(max<tmp)     max=tmp;
    }
    return dp[str][end]=max;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf(" %c",&a[i]);
    pair(1,n);
    printf("%d\n",dp[1][n]);
    return 0;
}
