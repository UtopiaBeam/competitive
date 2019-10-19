#include<stdio.h>
#include<stdlib.h>
int brd[50][50],n,cnt=0;
void play(int row){
    if(row==n){
        cnt++;      return ;
    }
    for(int k=0;k<n;k++){
        int chk=1;
        for(int i=0;i<row;i++){
            for(int j=0;j<n && chk;j++){
                if(brd[i][j] && (j==k || abs(i-row)==abs(j-k)))     chk=0;
            }
        }
        if(chk){
            brd[row][k]=1;
            play(row+1);
            brd[row][k]=0;
        }
    }
}
int main(){
    scanf("%d",&n);
    play(0);
    printf("%d\n",cnt);
    return 0;
}
