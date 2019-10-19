#include<stdio.h>
int a[1010][1010],r,c,cnt=0;
void play(int i,int j){
    if(i==r-1 && j==c-1){   cnt++;  return ;    }
    if(a[i][j]==0){
        play(i+1,j);    play(i,j+1);
    }
    if(a[i][j]==1)      play(i,j+1);
    if(a[i][j]==2)      play(i+1,j);
    if(a[i][j]==3)      return ;
}
int main(){
    scanf("%d %d",&r,&c);
    for(int i=r-1;i>=0;i--)
        for(int j=0;j<c;j++)
            scanf("%d",&a[i][j]);
    play(0,0);
    printf("%d\n",cnt);
    return 0;
}
