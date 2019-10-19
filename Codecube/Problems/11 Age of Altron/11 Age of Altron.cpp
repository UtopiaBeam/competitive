#include<cstdio>
int a[1005][1005],b[1005],n,m,k;
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=n;i>1;i--){
        b[i-1]=b[i];
        for(int j=1;j<=m;j++)
            if(!a[i][j])    b[i-1]++;
    }
    for(int i=1;i<=n;i++)
        for(int j=2;j<=m;j++)
            a[i][j]+=a[i][j-1];
    for(int i=n;i>0;i--)
        for(int j=k;j<=m;j++)
            if(a[i][j]-a[i][j-k]<=b[i]){
                printf("%d\n",i);
                return 0;
            }
}
