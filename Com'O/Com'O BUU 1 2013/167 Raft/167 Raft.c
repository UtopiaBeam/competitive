#include<stdio.h>
int a[10][10],b[10],c[10][10][10][10][10][10],cnt=0;
void play(int i,int j,int state){
    if(state==6){
        if(c[b[0]][b[1]][b[2]][b[3]][b[4]][b[5]]==1)   return ;
        cnt++;  c[b[0]][b[1]][b[2]][b[3]][b[4]][b[5]]=1;
        return ;
    }
    b[state]=a[i][j];
    if(i>0)     play(i-1,j,state+1);
    if(i<4)     play(i+1,j,state+1);
    if(j>0)     play(i,j-1,state+1);
    if(j<4)     play(i,j+1,state+1);
}
int main(){
    int i,j;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            play(i,j,0);
    printf("%d\n",cnt);
    return 0;
}
