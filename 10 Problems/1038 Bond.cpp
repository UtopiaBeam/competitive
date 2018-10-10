#include<cstdio>
int n;
double a[25][25],dp[1<<21]={1.0};
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            scanf("%lf",&a[i][j]);
            a[i][j]/=100;
        }
    for(int i=1;i<(1<<n);i++){
        int cnt=0;
        double max=0.0;
        for(int j=0;j<n;j++)
            if((i>>j)%2==0)     cnt++;
        for(int j=0;i>>j;j++){
            if((i>>j)%2==1){
                double tmp=a[j][cnt]*dp[i-(1<<j)];
                if(max<tmp)     max=tmp;
            }
        }
        dp[i]=max;
    }
    printf("%lf\n",dp[(1<<n)-1]*100);
    return 0;
}
