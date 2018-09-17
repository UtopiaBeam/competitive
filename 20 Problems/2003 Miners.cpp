#include<cstdio>
int n,dp[2][4][4][4][4],ans=-2e9,cur,pnt;
char s[100005];
int main(){
    scanf("%d %s",&n,s);
    for(int i=n-1;i>=0;i--){
        if(s[i]=='M')   cur=1;
        else if(s[i]=='F')  cur=2;
        else    cur=3;
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
                for(int l=0;l<4;l++)
                    for(int m=0;m<4;m++){
                        pnt=0;
                        if(j==1||k==1||cur==1)   pnt++;
                        if(j==2||k==2||cur==2)   pnt++;
                        if(j==3||k==3||cur==3)   pnt++;
                        if(dp[i%2][j][k][l][m]<dp[(i+1)%2][k][cur][l][m]+pnt)   dp[i%2][j][k][l][m]=dp[(i+1)%2][k][cur][l][m]+pnt;
                        pnt=0;
                        if(l==1||m==1||cur==1)   pnt++;
                        if(l==2||m==2||cur==2)   pnt++;
                        if(l==3||m==3||cur==3)   pnt++;
                        if(dp[i%2][j][k][l][m]<dp[(i+1)%2][j][k][m][cur]+pnt)   dp[i%2][j][k][l][m]=dp[(i+1)%2][j][k][m][cur]+pnt;
                    }
    }
    printf("%d\n",dp[0][0][0][0][0]);
    return 0;
}
