//O(n^2) to O(nlogn)
#include<cstdio>
#include<algorithm>
using namespace std;
long long sum[100005];
int dp[100005],b[100005],len=0;
int main(){
    int a,n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        sum[i]=a+sum[i-1];
    }
    //LIS to optimize
    for(int i=1;i<=n;i++){
        int l=1,r=len;
        while(l<=r){
            int mid=(l+r)/2;
            if(sum[b[mid]]<sum[i])
        }
//        for(int j=0;j<i;j++)
//            if(sum[i]-sum[j]>0)   dp[i]=max(dp[i],dp[j]+1);
    }
    for(int i=1;i<=n;i++)
        printf("%d ",dp[i]);
    printf("\n");
    return 0;
}
