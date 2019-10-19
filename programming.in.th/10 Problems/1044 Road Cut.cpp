#include<stdio.h>
int r,c,a[105][105],b[105][105],max=-1<<20;
int main(){
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++){
            scanf("%d",&a[i][j]);
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++){
            scanf("%d",&b[i][j]);
            b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
        }
    for(int i=1;i<=r;i++){
        int total=a[r][c]-a[i][c]+a[i-1][c];
        if(i>1)     total+=b[i-1][c]-b[i-2][c];
        if(i<r)     total+=b[i+1][c]-b[i][c];
        if(max<total)   max=total;
    }
    for(int i=1;i<=c;i++){
        int total=a[r][c]-a[r][i]+a[r][i-1];
        if(i>1)     total+=b[r][i-1]-b[r][i-2];
        if(i<c)     total+=b[r][i+1]-b[r][i];
        if(max<total)   max=total;
    }
    printf("%d\n",max);
    return 0;
}
