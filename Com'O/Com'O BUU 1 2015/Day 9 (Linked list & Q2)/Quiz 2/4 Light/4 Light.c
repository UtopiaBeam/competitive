#include<stdio.h>
int a[102][102],r,c,n,x,y;
int main(){
    scanf("%d %d %d",&r,&c,&n);
    while(n--){
        scanf("%d %d",&x,&y);
        a[x][y]=1-a[x][y];
        if(x>1) a[x-1][y]=1-a[x-1][y];
        if(x<r) a[x+1][y]=1-a[x+1][y];
        if(y>1) a[x][y-1]=1-a[x][y-1];
        if(y<c) a[x][y+1]=1-a[x][y+1];
    }
    int i,j;
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
