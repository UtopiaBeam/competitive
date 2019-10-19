#include<cstdio>
#include<algorithm>
using namespace std;
int n,r[12],c[12],dp[12][12];
int f(int s,int e){
    if(s==e)        return dp[s][e]=0;
    if(dp[s][e])    return dp[s][e];
    int t=1e9;
    for(int i=s;i<e;i++){
        if(!dp[s][i])   f(s,i);
        if(!dp[i+1][e]) f(i+1,e);
        t=min(t,dp[s][i]+dp[i+1][e]+r[s]*c[i]*c[e]);
    }
    return dp[s][e]=t;
}
void p(int s,int e){
    if(s==e){
        printf("A%d",s+1);
        return ;
    }
    printf("(");
    for(int i=s;i<e;i++){
        if(dp[s][e]==dp[s][i]+dp[i+1][e]+r[s]*c[i]*c[e]){
            p(s,i);
            printf(" x ");
            p(i+1,e);
            break;
        }
    }
    printf(")");
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&r[i],&c[i]);
    f(0,n-1);
    printf("%d\n",dp[0][n-1]);
    p(0,n-1);
    return 0;
}
