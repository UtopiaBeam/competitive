#include<cstdio>
#include<stack>
using namespace std;
int n,dp[1002],pre[1002],a[1002],mx=0;
stack<int> ans;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        dp[i]=1,pre[i]=i;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(a[i]>a[j] && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                pre[i]=j;
            }
    for(int i=0;i<n;i++)
        if(dp[mx]<dp[i])    mx=i;
    printf("%d\n",dp[mx]);
    while(pre[mx]!=mx){
        ans.push(mx);
        mx=pre[mx];
    }
    ans.push(mx);
    while(!ans.empty()){
        printf("%d ",a[ans.top()]);
        ans.pop();
    }
    return 0;
}
