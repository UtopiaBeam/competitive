#include<cstdio>
#include<vector>
using namespace std;
vector <int> pos;
int dp[20005],sum[20005];
int main(){
    int a,n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        sum[i]=a+sum[i-1];
        if(a>0) pos.push_back(i);
    }
    for(int i=0;i<pos.size();i++)
        dp[i]=i+1;
    for(int i=0;i<pos.size();i++){
        if(sum[pos[i]]-sum[pos[0]-1]>0)
            dp[i]=1;
        else{
            bool chk=true;
            for(int j=0;j<i;j++){
                if(sum[pos[i]]-sum[pos[j+1]-1]>0 && dp[j]+1<dp[i])
                    dp[i]=dp[j]+1,chk=false;
            }
            if(chk)     dp[i]=dp[i-1]+1;
        }
    }
    printf("%d\n",dp[pos.size()-1]);
    return 0;
}
