#include<cstdio>
int dp[305][305][305],a[305][305],r,c;
int main(){
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            scanf("%d",&a[r-i+1][j]);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            for(int k=1;k<=c;k++){

            }
    return 0;
}
