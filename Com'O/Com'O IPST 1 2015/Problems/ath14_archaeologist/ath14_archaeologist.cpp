#include<cstdio>
#include<algorithm>
using namespace std;
int r,c,dp[2][302][302],a[302][302];
int s[4]={-1,0,1};
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<c;i++)
        for(int j=0;j<c;j++)
            dp[0][i][j]=a[0][i]+(i!=j)*a[0][j];
    for(int i=1;i<r;i++)
        for(int j=0;j<c;j++)
            for(int k=0;k<c;k++)
                if(j>k)     dp[i%2][j][k]=dp[i%2][k][j];
                else{
                    int mx=-1e9;
                    for(int tj=0;tj<3;tj++)
                        for(int tk=0;tk<3;tk++){
                            int pj=j+s[tj],pk=k+s[tk];
                            if(pj>=0 && pj<c && pk>=0 && pk<c)
                                mx=max(mx,dp[(i+1)%2][pj][pk]);
                        }
                    dp[i%2][j][k]=mx+a[i][j]+(j!=k)*a[i][k];
                }
    int mx=-1e9;
    for(int i=0;i<c;i++)
        mx=max(mx,dp[(r+1)%2][i][i]);
    printf("%d\n",mx);
    return 0;
}
