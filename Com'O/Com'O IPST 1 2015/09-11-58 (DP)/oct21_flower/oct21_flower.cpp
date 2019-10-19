#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define P pair<int,int>
#define w first
#define v second
vector<P> a[2];
int dp[102];
int KS(int W,int t){
    memset(dp,0,sizeof(dp));
    for(int i=0;i<a[t].size();i++){
        for(int j=W;j>=0;j--)
            if(j>=a[t][i].w)    dp[j]=max(dp[j],dp[j-a[t][i].w]+a[t][i].v);
    }
    return dp[W];
}
int main(){
    int n,W,mx=0;
    scanf("%d %d",&W,&n);
    for(int i=0;i<n;i++){
        int w,v,t;
        scanf("%d %d %d",&w,&v,&t);
        a[t].push_back(P(w,v));
    }
    for(int w=0;w<=W;w++)
        mx=max(mx,KS(w,0)+KS(W-w,1));
    printf("%d\n",mx);
    return 0;
}
