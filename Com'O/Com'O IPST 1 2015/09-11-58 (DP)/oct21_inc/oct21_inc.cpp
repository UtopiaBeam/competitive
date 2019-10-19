#include<cstdio>
#include<stack>
using namespace std;
int n,a[1002],dp[1002],pre[1002],mx=0;
stack<int> s;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        dp[i]=1;    pre[i]=i;
    }
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(a[j]<a[i] && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                pre[i]=j;
            }
    for(int i=1;i<n;i++)
        if(dp[mx]<dp[i])    mx=i;
    printf("%d\n",dp[mx]);
    while(true){
        s.push(a[mx]);
        if(mx==pre[mx])     break;
        mx=pre[mx];
    }
    while(!s.empty()){
        printf("%d ",s.top());
        s.pop();
    }
    return 0;
}
