#include<cstdio>
#include<algorithm>
using namespace std;
long long dp[605][605],a[605];
int n;
long long f(int s,int e){
    if(s>=e || dp[s][e])    return dp[s][e];
    long long tmp=0,sum;
    for(int i=s;i<e;i++){
        if(a[i]-a[s-1]<=a[e]-a[i])
            sum=2*(a[i]-a[s-1])+a[e]-a[i];
        else    sum=a[i]-a[s-1]+2*(a[e]-a[i]);
        if(!dp[s][i])    f(s,i);
        if(!dp[i+1][e])  f(i+1,e);
        tmp=max(tmp,sum+dp[s][i]+dp[i+1][e]);
    }
    return dp[s][e]=tmp;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<n;i++)
        a[i]+=a[i-1];
    f(0,n-1);
    printf("%lld\n",dp[0][n-1]);
    return 0;
}
