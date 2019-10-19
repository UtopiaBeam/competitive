#include<cstdio>
#include<deque>
#include<algorithm>
using namespace std;
int r,c,k,a[10002],dp[102][10002],mx[10002],ans=0;
deque<int> d;
int main(){
    scanf("%d %d %d",&r,&c,&k);
    k++;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++)
            scanf("%d",&a[j]);
        for(int j=1;j<k;j++){
            while(!d.empty() && dp[i-1][d.back()]<dp[i-1][j])
                d.pop_back();
            d.push_back(j);
            mx[j]=dp[i-1][d.front()];
        }
        for(int j=k;j<=c;j++){
            while(!d.empty() && dp[i-1][d.back()]<dp[i-1][j])
                d.pop_back();
            d.push_back(j);
            while(d.front()<=j-k)   d.pop_front();
            mx[j]=dp[i-1][d.front()];
        }
        d.clear();
        for(int j=c;j>c-k+1;j--){
            while(!d.empty() && dp[i-1][d.back()]<dp[i-1][j])
                d.pop_back();
            d.push_back(j);
            if(mx[j]<dp[i-1][d.front()])
                mx[j]=dp[i-1][d.front()];
        }
        for(int j=c-k+1;j>0;j--){
            while(!d.empty() && dp[i-1][d.back()]<dp[i-1][j])
                d.pop_back();
            d.push_back(j);
            while(d.front()>=j+k)   d.pop_front();
            if(mx[j]<dp[i-1][d.front()])
                mx[j]=dp[i-1][d.front()];
        }
        d.clear();
        for(int j=1;j<=c;j++)
            dp[i][j]=a[j]+mx[j];
    }
    for(int j=1;j<=c;j++)
        ans=max(ans,dp[r][j]);
    printf("%d\n",ans);
    return 0;
}
