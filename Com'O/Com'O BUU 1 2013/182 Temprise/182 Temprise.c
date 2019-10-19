#include<stdio.h>
int a[30][30],max=-20,n;
void play(int i,int j){
    if(i<1||j<1||i>n||j>n)  return ;
    if(a[i][j]<a[i-1][j])   play(i-1,j);
    if(a[i][j]<a[i+1][j])   play(i+1,j);
    if(a[i][j]<a[i][j-1])   play(i,j-1);
    if(a[i][j]<a[i][j+1])   play(i,j+1);
    if(max<a[i][j])     max=a[i][j];
}
int main(){
    int i,j,x,y;
    scanf("%d %d %d",&n,&y,&x);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==100)    a[i][j]=-10;
        }
    play(x,y);
    printf("%d\n",max);
    return 0;
}
