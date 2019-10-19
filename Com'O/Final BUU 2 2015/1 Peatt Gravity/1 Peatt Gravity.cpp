#include<cstdio>
#include<cmath>
int n,m,k,mn=1<<30,x[15],y[15],t[15],b[15],d[15][15];
void f(int i,int cost){
    if(cost+d[i][k+1]<mn)   mn=cost+d[i][k+1];
    for(int j=1;j<=k;j++)
        if(!b[j]){
            b[j]=1;
            f(j,cost+d[i][j]);
            b[j]=0;
        }
}
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=k;i++)
        scanf("%d %d %d",&x[i],&y[i],&t[i]);
    x[0]=0,y[0]=0,t[0]=0;
    x[k+1]=n-1,y[k+1]=m-1,t[k+1]=0;
    for(int i=0;i<=k;i++)
        for(int j=i+1;j<=k+1;j++){
            int tmp=ceil(sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
            d[i][j]=tmp-t[j];
            d[j][i]=tmp-t[i];
        }
    f(0,0);
    printf("%d\n",mn);
    return 0;
}
