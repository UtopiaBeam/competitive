#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[105][105],a[105],b[105],n,k;
int f(int str,int end){
    if(dp[str][end]>0)    return dp[str][end];
    int tmp=0;
    int t=a[end]-a[str-1],c=b[end]-b[str-1];
    if(t/c==k)  tmp=t;
    else for(int i=str;i<end;i++)
        tmp=max(f(str,i),f(i+1,end));
    return dp[str][end]=tmp;
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        b[i]+=b[i-1];
    }
    f(1,n);
    if(dp[1][n])    printf("%d\n",dp[1][n]);
    else    printf("-1\n");
    return 0;
}
