#include<cstdio>
#include<algorithm>
using namespace std;
int r,c,n,a[12],x[12],y[12],p[12],d[12][12],mn;
int main(){
    scanf("%d %d %d",&r,&c,&n);
    for(int i=1;i<=n;i++)    scanf("%d %d %d",&x[i],&y[i],&p[i]),a[i]=i;
    x[n+1]=r-1,y[n+1]=c-1,p[0]=p[n+1]=0,a[n+1]=n+1;
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=n+1;j++)
            d[i][j]=(int)ceil(sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2)));
    int mn=d[0][n+1];
    do{
        int dt=0;
        for(int i=0;i<=n;i++){
            mn=min(mn,dt+d[a[i]][n+1]);
            dt+=d[a[i]][a[i+1]]-p[a[i+1]];
        }
    }while(next_permutation(a+1,a+n+1));
    printf("%d\n",mn);
    return 0;
}
