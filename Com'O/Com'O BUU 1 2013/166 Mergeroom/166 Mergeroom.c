#include<stdio.h>
int a[60][60],b[60][60],r,c,max=0,room=0,cnt;
void play(int i,int j,int state){
    int k;
    if(i<1||j<1||i>r||j>c)      return ;
    if(b[i][j]==1)              return ;
    b[i][j]=1,k=a[i][j],cnt++;
    if(k%2==0)        play(i,j-1,state);
    else if(!state)     play(i,j-1,1);
    if((k/2)%2==0)    play(i-1,j,state);
    else if(!state)     play(i-1,j,1);
    if((k/4)%2==0)    play(i,j+1,state);
    else if(!state)     play(i,j+1,1);
    if((k/8)%2==0)    play(i+1,j,state);
    else if(!state)     play(i+1,j,1);
}
int main(){
    int i,j;
    scanf("%d %d",&c,&r);
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            if(b[i][j]!=1){
                cnt=0;
                play(i,j,0);
                if(max<cnt)     max=cnt;
            }
    printf("%d\n",max);
    return 0;
}
