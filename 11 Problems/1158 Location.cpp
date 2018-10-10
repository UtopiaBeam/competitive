#include<cstdio>
#include<algorithm>
using namespace std;
int a[1010][1010],r,c,k,ans=0;
int main(){
    scanf("%d %d %d",&r,&c,&k);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++){
            scanf("%d",&a[i][j]);
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    for(int i=k;i<=r;i++)
        for(int j=k;j<=c;j++)
            ans=max(ans,a[i][j]-a[i-k][j]-a[i][j-k]+a[i-k][j-k]);
    printf("%d\n",ans);
    return 0;
}
