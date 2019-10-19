#include<cstdio>
#include<climits>
int r,c,p[102][102],s[3]={-1,0,1};
long long a[102][102],dp[102][102],mn=0;
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)
        for(int j=c;j>0;j--){
            scanf("%lld",&a[i][j]);
            dp[i][j]=LLONG_MAX;
        }
    for(int j=1;j<=c;j++)
        for(int i=0;i<r;i++)
            for(int k=0;k<3;k++){
                int ni=(i+s[k]+r)%r;
                long long t=dp[ni][j-1]+a[i][j];
                if(dp[i][j]>t){
                    dp[i][j]=t;     p[i][j]=ni;
                }
            }
    for(int i=0;i<r;i++)
        if(dp[i][c]<dp[mn][c])
            mn=i;
    printf("%lld\n",dp[mn][c]);
    for(int j=c;j>0;j--){
        printf("%d ",mn+1);
        mn=p[mn][j];
    }
    return 0;
}
