#include<cstdio>
#include<cstring>
int r,c,dp[122][122][2],cnt=0,mx=0;
char a[122][122];
int dfs(int i,int j,int d){
    if(dp[i][j][d])     return dp[i][j][d];
    if(a[i][j]=='$')    return 1;
    if(a[i][j]=='@')    return -1;
    if(a[i][j]=='.')    return dp[i][j][d]=dfs(i+1,j,d);
    if(j==0 && d==0 || j==c-1 && d==1)    return dp[i][j][d]=dfs(i,j,1-d);
    if(d==0)    return dp[i][j][d]=dfs(i,j-1,d);
    return dp[i][j][d]=dfs(i,j+1,d);
}
int main(){
    scanf("%d %d",&c,&r);
    for(int i=0;i<r;i++)    scanf(" %s",a[i]);
    for(int j=0;j<c;j++)
        cnt+=(dfs(0,j,0)>0)+(dfs(0,j,1)>0);
    printf("%d ",cnt);
    for(int i=0;i<r-1;i++)
        for(int k=0;k<c;k++)
            if(a[i][k]=='#'){
                a[i][k]='.';
                cnt=0;  memset(dp,0,sizeof(dp));
                for(int j=0;j<c;j++)
                    cnt+=(dfs(0,j,0)>0)+(dfs(0,j,1)>0);
                if(mx<cnt)      mx=cnt;
                a[i][k]='#';
            }
    printf("%d\n",mx);
    return 0;
}
