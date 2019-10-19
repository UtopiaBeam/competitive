#include<cstdio>
int n,K,a[102],op[22][22],chk[102][102];
int dp[102][102][22];
void f(int s,int e){
    if(chk[s][e])       return ;
    chk[s][e]=1;
    if(s==e)        dp[s][e][a[s]]=1;
    for(int i=s;i<e;i++){
        f(s,i);     f(i+1,e);
        for(int j=0;j<K;j++)
            for(int k=0;k<K;k++){
                dp[s][e][op[j][k]]+=dp[s][i][j]*dp[i+1][e][k];
                dp[s][e][op[j][k]]%=2009;
            }
    }
}
int main(){
    scanf("%d",&K);
    for(int i=0;i<K;i++)
        for(int j=0;j<K;j++)
            scanf("%d",&op[i][j]);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    f(0,n-1);
    for(int i=0;i<K;i++)
        printf("%d\n",dp[0][n-1][i]);
    return 0;
}
