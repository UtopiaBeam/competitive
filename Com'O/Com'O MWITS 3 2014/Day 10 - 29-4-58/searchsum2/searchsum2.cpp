#include<cstdio>
#include<algorithm>
using namespace std;
int a[1005],sum[1005],n,k,m;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    for(int l=1;l<=n;l++){
        int tmp_min=2e9;
        for(int i=1;i<=n-l+1;i++)
            tmp_min=min(tmp_min,a[i+l-1]-a[i-1]);
        sum[l]=tmp_min;
    }
    while(k--){
        scanf("%d",&m);
        int in=upper_bound(sum+1,sum+n+1,m)-(sum+1);
        printf("%d\n",in);
    }
    return 0;
}
