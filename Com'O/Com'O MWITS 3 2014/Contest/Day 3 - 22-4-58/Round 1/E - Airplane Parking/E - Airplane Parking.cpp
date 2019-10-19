#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
pair <int,int> a[305];
int dp[305],t,n;
int main(){
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<300;i++)  dp[i]=1;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d %d",&a[i].first,&a[i].second);
        sort(a,a+n);
        for(int i=0;i<n;i++)
            for(int j=0;j<i;j++){
                if(a[i].first<a[j].second && a[i].second>a[j].second)     continue;
                dp[i]=max(dp[i],dp[j]+1);
            }
        printf("%d\n",dp[n-1]);
    }
    return 0;
}
