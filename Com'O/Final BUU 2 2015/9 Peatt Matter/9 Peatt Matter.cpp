#include<cstdio>
#include<cstring>
int q,n,a[102];
long long dp[20002];
int main(){
    scanf("%d",&q);
    while(q--){
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        int sum=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            a[i]+=100;
            sum+=a[i];
        }
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=sum;j>=a[i];j--){
                dp[j]|=dp[j-a[i]]*2;
                dp[j]&=((long long)1<<(n/2+1))-1;
            }
        }
        for(int i=sum/2;i>=0;i--){
            if(((long long)dp[i]>>(n/2))%2){
                printf("%d\n",sum-2*i);
                break;
            }
        }
    }
    return 0;
}
