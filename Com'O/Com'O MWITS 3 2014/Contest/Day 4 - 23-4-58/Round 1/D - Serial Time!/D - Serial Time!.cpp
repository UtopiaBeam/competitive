#include<cstdio>
char a[15][15][15];
int r,c,h,x,y,X[6]={-1,1,0,0,0,0},Y[6]={0,0,-1,1,0,0},Z[6]={0,0,0,0,-1,1},mark[15][15][15],cnt=0;
void dfs(int i,int j,int k){
    if(mark[i][j][k] || a[i][j][k]=='#')   return ;
    cnt++,mark[i][j][k]=1;
    for(int l=0;l<6;l++){
        int ni=i+X[l],nj=j+Y[l],nk=k+Z[l];
        if(ni>0 && nj>0 && nk>0 && ni<=r && nj<=c && nk<=h)
            dfs(ni,nj,nk);
    }
}
int main(){
    scanf("%d %d %d",&h,&r,&c);
    for(int i=1;i<=h;i++)
        for(int j=1;j<=r;j++)
            for(int k=1;k<=c;k++)
                scanf(" %c",&a[j][k][i]);
    scanf("%d %d",&x,&y);
    dfs(x,y,1);
    printf("%d\n",cnt);
    return 0;
}
