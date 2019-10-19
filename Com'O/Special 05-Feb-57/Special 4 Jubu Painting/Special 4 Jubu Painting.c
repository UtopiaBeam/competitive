#include<stdio.h>
int r,c,a[105][105];
void play(int i,int j){
    if(i<0||j<0||i>=r||j>=c)    return ;
    if(a[i][j]!=2)              return ;
    a[i][j]=1;
    play(i-1,j);    play(i+1,j);    play(i,j-1);    play(i,j+1);
}
int main(){
    int i,j,x,y,chk=1;
    char ch;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            scanf(" %c",&ch);
            if(ch=='+')     a[i][j]=0;
            else            a[i][j]=2;
        }
    for(i=0;i<c;i++)
        if(a[0][i]==2)      play(0,i);
    for(i=0;i<r&&chk;i++)
        if(a[i][0]==2)      play(i,0);
    for(i=0;i<c&&chk;i++)
        if(a[r-1][i]==2)    play(r-1,i);
    for(i=0;i<r&&chk;i++)
        if(a[i][c-1]==2)    play(i,c-1);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(a[i][j]==0)  printf("+");
            if(a[i][j]==1)  printf(".");
            if(a[i][j]==2)  printf("#");
        }
        printf("\n");
    }
    return 0;
}
