#include<cstdio>
#include<algorithm>
int W,n,w,v;
int dp[2002];
int main(){
    scanf("%d %d",&W,&n);
    while(n--){
        scanf("%d %d",&w,&v);
        for(int i=W;i>=0;i--)
            if(i>=w)    dp[i]=std::max(dp[i],dp[i-w]+v);
    }
    printf("%d\n",dp[W]);
    return 0;
}
