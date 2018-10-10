#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
long long dp[1000010]={0,0,1};
vector <int> p;
int main(){
    int q,a,b;
    for(int i=3;i<=1000000;i+=2)
        dp[i]=1;
    for(int i=3;i*i<=1000000;i+=2)
        if(dp[i])
            for(int j=i*i;j<=1000000;j+=i)  dp[j]=0;
    for(int i=2;i<1000000;i++)
        if(dp[i])   p.push_back(i);
    dp[1]=1;
    for(int i=2;i<=1000000;i++)     dp[i]=0;
    for(int i=0;i<p.size();i++)     dp[p[i]]=2;
    for(int i=4;i<=1000000;i++){
        if(!dp[i]){
            int t=i;
            long long cnt=0;
            for(int j=0;p[j]*p[j]<=i;j++){
                while(t%p[j]==0)    t/=p[j],cnt++;
                if(dp[t]){
                    dp[i]=dp[t]*(cnt+1);    break;
                }
            }
        }
    }
    scanf("%d",&q);
    while(q--){
        long long cnt=0,n;
        scanf("%d %d %lld",&a,&b,&n);
        for(int i=a;i<=b;i++)
            if(dp[i]==n)    cnt++;
        printf("%lld\n",cnt);
    }
    return 0;
}
