#include<cstdio>
#include<algorithm>
#define L long long
using namespace std;
int r,c,d[4][2]={{1,0},{0,1},{-1,0},{0,-1}},mx=0;
L dp[302][302][4];
char a[302][302];
void init(){
for(int i=r-1;i>=0;i--)
    for(int j=c-1;j>=0;j--)
        for(int k=0;k<2;k++){
            int pi=i+d[k][0],pj=j+d[k][1];
            if(pi<0 || pi>=r || pj<0 || pj>=c)
                dp[i][j][k]=0;
            else    dp[i][j][k]=dp[pi][pj][k]<<1;
            dp[i][j][k]|=(a[i][j]=='1');
        }
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            for(int k=2;k<4;k++){
                int pi=i+d[k][0],pj=j+d[k][1];
                if(pi<0 || pi>=r || pj<0 || pj>=c)
                    dp[i][j][k]=0;
                else    dp[i][j][k]=dp[pi][pj][k]<<1;
                dp[i][j][k]|=(a[i][j]=='1');
            }
}
bool chk(int i,int j,int s){
    if(i<0 || i+s>=r || j<0 || j+s>=c)
        return false;
    for(int k=0;k<2;k++){
        int si=i,sj=j;
        int ei=i+s,ej=j+s;
        for(int sz=s+1;sz>0;sz-=64){
            L x=dp[si][sj][k],y=dp[ei][ej][k+2];
            if(sz>=64){
                if(x^y)     return false;
            }
            else if((x^y) & ((1LL<<sz)-1))
                return false;
            si+=d[k][0]*64,sj+=d[k][1]*64;
            ei-=d[k][0]*64,ej-=d[k][1]*64;
        }
    }
    return true;
}
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)
        scanf(" %s",a[i]);
    init();
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            for(int s=0;s<2;s++){
                int sz=s;
                while(chk(i-sz/2,j-sz/2,sz))
                    sz+=2;
                mx=max(mx,sz-1);
            }
    if(mx>1)    printf("%d\n",mx);
    else        printf("-1\n");
    return 0;
}
