#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[102],dp[102][102];
int f(int s,int e){
    if(s>e)     return 0;
    if(dp[s][e])    return dp[s][e];
    if(s==e)    return dp[s][e];
    return dp[s][e]=max(a[s]+max(f(s+2,e),f(s+1,e-1)),a[e]+max(f(s,e-2),f(s+1,e-1)));
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++){
        scanf("%d",a+i);
        dp[i][i]=a[i];
    }
    printf("%d\n",f(1,2*n));
    return 0;
}
