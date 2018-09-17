#include<stdio.h>
#include<string.h>
int a[110][110],b[110][110],r,c;
void play(int i,int j){
    if(b[i][j]==1){
        printf("NO\n");
        return ;
    }
    b[i][j]=1;
    if(a[i][j]==1)
        if(i==1){
            printf("N\n");
            return ;
        }
        else    play(i-1,j);
    if(a[i][j]==2)
        if(j==c){
            printf("E\n");
            return ;
        }
        else    play(i,j+1);
    if(a[i][j]==3)
        if(i==r){
            printf("S\n");
            return ;
        }
        else    play(i+1,j);
    if(a[i][j]==4)
        if(j==1){
            printf("W\n");
            return ;
        }
        else    play(i,j-1);
}
int main(){
    int n,x,y,i,j;
    scanf("%d %d %d",&c,&r,&n);
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            scanf("%d",&a[i][j]);
    while(n--){
        memset(b,0,sizeof(b));
        scanf("%d %d",&y,&x);
        play(x,y);
    }
    return 0;
}
