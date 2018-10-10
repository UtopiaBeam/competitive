#include<cstdio>
int a[1005][1005],n,m,x,y,k;
int main(){
    scanf("%d %d",&n,&m);
    while(n--){
        scanf("%d %d",&x,&y);
        a[x][y]++;
    }
    for(int i=0;i<=1000;i++)
        for(int j=0;j<=1000;j++){
           if(i>0)  a[i][j]+=a[i-1][j];
           if(j>0)  a[i][j]+=a[i][j-1];
           if(i>0 && j>0)  a[i][j]-=a[i-1][j-1];
        }
    while(m--){
        scanf("%d %d %d",&x,&y,&k);
        int lx,ly,rx,ry;
        if(x-k>0)   lx=x-k;
        else    lx=0;
        if(y-k>0)   ly=y-k;
        else    ly=0;
        if(x+k<1001)    rx=x+k;
        else    rx=1000;
        if(y+k<1001)    ry=y+k;
        else    ry=1000;
        printf("%d\n",a[rx][ry]-a[lx-1][ry]*(lx>0)-a[rx][ly-1]*(ly>0)+a[lx-1][ly-1]*(lx>0 && ly>0));
    }
    return 0;
}
