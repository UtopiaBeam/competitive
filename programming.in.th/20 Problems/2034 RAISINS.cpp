#include<cstdio>
#include<algorithm>
using namespace std;
int  cost[55][55][55][55],a[55][55],r,c;
int play(int r1,int c1,int r2,int c2){
    if(cost[r1][c1][r2][c2]!=0) return cost[r1][c1][r2][c2];
    if(r1==r2 && c1==c2)    return cost[r1][c1][r2][c2]=0;
    int Min=1000000000,i;
    for(i=r1;i<r2;i++)
        Min=min(Min,play(r1,c1,i,c2)+play(i+1,c1,r2,c2)+a[r2][c2]-a[r1-1][c2]-a[r2][c1-1]+a[r1-1][c1-1]);
    for(i=c1;i<c2;i++)
        Min=min(Min,play(r1,c1,r2,i)+play(r1,i+1,r2,c2)+a[r2][c2]-a[r1-1][c2]-a[r2][c1-1]+a[r1-1][c1-1]);
    return cost[r1][c1][r2][c2]=Min;
}
int main(){
    int i,j,n;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++){
            scanf("%d",&n);
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+n;
        }
    printf("%d\n",play(1,1,r,c));
    return 0;
}
