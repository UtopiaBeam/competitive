#include<stdio.h>
int a[510][510],r,c,min=-1u/2;
int main(){
    int i,j,k;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            scanf("%d",&a[i][j]);
    for(i=2;i<=r;i++){
        for(j=1;j<=c;j++){
            if(j==1)
                a[i][j]+=(a[i-1][j]<a[i-1][j+1])?   a[i-1][j]:a[i-1][j+1];
            else if(j==c)
                a[i][j]+=(a[i-1][j-1]<a[i-1][j])?   a[i-1][j-1]:a[i-1][j];
            else{
                k=(a[i-1][j-1]<a[i-1][j])?     a[i-1][j-1]:a[i-1][j];
                k=(k<a[i-1][j+1])?      k:a[i-1][j+1];
                a[i][j]+=k;
            }
        }
    }
    for(j=1;j<=c;j++)
        if(min>a[r][j])     min=a[r][j];
    printf("%d\n",min);
    return 0;
}
