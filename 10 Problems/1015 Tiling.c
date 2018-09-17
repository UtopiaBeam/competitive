#include<stdio.h>
int n,cnt,a[20][20],b[20][20];
void play(int i,int j,int *c){
    if(b[i][j]==1)  return;
    b[i][j]=1,(*c)++;
    if(a[i+1][j]==a[i][j] && b[i+1][j]==0)    play(i+1,j,c);
    if(a[i-1][j]==a[i][j] && b[i-1][j]==0)    play(i-1,j,c);
    if(a[i][j+1]==a[i][j] && b[i][j+1]==0)    play(i,j+1,c);
    if(a[i][j-1]==a[i][j] && b[i][j-1]==0)    play(i,j-1,c);
}
void check(int i,int j){
    int chk=0;
    if(b[i][j]==1||a[i][j]==0)  return;
    if((a[i][j]==a[i+1][j] && a[i][j]==a[i][j+1]) && !b[i+1][j] && !b[i][j+1])       play(i,j,&chk);
    else if((a[i][j]==a[i-1][j] && a[i][j]==a[i][j-1]) && !b[i-1][j] && !b[i][j-1])  play(i,j,&chk);
    else if((a[i][j]==a[i+1][j] && a[i][j]==a[i][j-1]) && !b[i+1][j] && !b[i][j-1])  play(i,j,&chk);
    else if((a[i][j]==a[i-1][j] && a[i][j]==a[i][j+1]) && !b[i-1][j] && !b[i][j+1])  play(i,j,&chk);
    if(chk==3)   cnt++;
}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            check(i,j);
    printf("%d",cnt);
    return 0;
}
