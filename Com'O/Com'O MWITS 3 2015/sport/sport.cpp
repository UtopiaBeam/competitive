#include<cstdio>
#include<algorithm>
using namespace std;
int dp[(1<<20)+2],a[22][22],b[22][3],n,m;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
        for(int j=0;j<3;j++)
            scanf("%d",&b[i][j]);
    for(int i=0;i<n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<(1<<n);i++){
        int cnt=0,mx=0;
        for(int j=0;i>>j;j++)
            cnt+=(i>>j)%2;
        for(int j=0;i>>j;j++){
            if((i>>j)%2){
                int t=dp[i-(1<<j)]+a[j][cnt];
                mx=max(mx,t);
            }
        }
        for(int j=0;j<m;j++)
            if(cnt==b[j][0] && mx>=b[j][1])
                mx+=b[j][2];
        dp[i]=mx;
    }
    printf("%d\n",dp[(1<<n)-1]);
    return 0;
}
