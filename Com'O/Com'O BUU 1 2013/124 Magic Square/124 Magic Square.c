#include<stdio.h>
int square[30][30],lim,n;
void fill(int i,int j,int k){
    int newi,newj;
    if(k==lim)      return ;
    square[i][j]=k;
    if(i>0) newi=i-1;
    else    newi=n-1;
    if(j<n-1)   newj=j+1;
    else        newj=0;
    if(square[newi][newj]){
        if(i<n-1) newi=i+1;
        else      newi=0;
        newj=j;
    }
    fill(newi,newj,k+1);
}
int main(){
    int k,i,j;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            square[i][j]=0;
    lim=k+n*n;
    fill(0,n/2,k);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d ",square[i][j]);
        printf("\n");
    }
    return 0;
}
