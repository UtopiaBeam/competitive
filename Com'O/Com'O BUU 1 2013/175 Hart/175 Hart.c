#include<stdio.h>

int main(){
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    int board[n+2][m+2];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&board[i][j]);       //scan board
    int r,oprt,pos,num;
    scanf("%d",&r);
    while(r--){
        scanf("%d %d %d",&oprt,&pos,&num);
        if(oprt==1){
            for(i=1;i<=m;i++)
                board[pos][i]=num;
        }
        else{
            for(i=1;i<=n;i++)
                board[i][pos]=num;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
            printf("%d ",board[i][j]);
        printf("\n");
    }
    return 0;
}
