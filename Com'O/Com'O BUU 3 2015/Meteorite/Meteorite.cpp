#include<cstdio>
int n,m,a,b,c,dp[1002];
double x,y;
int main(){
    scanf("%d %d",&n,&m);
    while(n--){
        scanf("%d %d %d",&a,&b,&c);
        dp[a]++;    dp[b]--;
    }
    for(int i=1;i<=1000;i++)
        dp[i]+=dp[i-1];
    while(m--){
        scanf("%lf %lf",&x,&y);
        printf("%d\n",dp[(int)x]);
    }
    return 0;
}
