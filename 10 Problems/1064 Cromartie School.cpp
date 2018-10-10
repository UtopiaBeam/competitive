#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[70][70];
int r,c,dp[70][70],p[70][70],maxs=0,cnt=1,mincnt=1<<20,chk[1000];
void play(int i,int j){
    int d[]={-1,1,0,0};
    p[i][j]=cnt;
    for(int k=0;k<4;k++){
        int newi=i+d[k],newj=j+d[3-k];
        if(newi>=0 && newi<r && newj>=0 && newj<c && p[newi][newj]==0 && a[newi][newj]=='P')
            play(newi,newj);
    }
}
int main(){
    scanf("%d %d",&c,&r);
    for(int i=0;i<r;i++)
        scanf(" %s",a[i]);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(a[i][j]=='P' && p[i][j]==0){
                play(i,j);  cnt++;
            }
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            if(a[i][j]=='T')    continue;
            if(i==0 && j==0)    dp[i+1][j+1]=1;
            else    dp[i+1][j+1]=1+min(dp[i+1][j],min(dp[i][j+1],dp[i][j]));
            maxs=max(maxs,dp[i+1][j+1]);
        }
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++){
            memset(chk,0,sizeof(chk)),cnt=0;
            if(dp[i][j]==maxs){
                for(int k=i-maxs;k<i;k++){
                    for(int l=j-maxs;l<j;l++)
                        if(a[k][l]=='P' && chk[p[k][l]]==0)
                            chk[p[k][l]]=1,cnt++;
                }
                mincnt=min(mincnt,cnt);
            }
        }
    printf("%d %d\n",maxs*maxs,mincnt);
    return 0;
}
