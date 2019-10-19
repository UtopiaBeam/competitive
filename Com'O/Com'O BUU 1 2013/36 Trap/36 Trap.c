#include<stdio.h>
int n,a[1002][1002];
int main(){
    scanf("%d",&n);
    int i=1,j=n,k=0,nw=1;
    while(nw<=n*n){
        a[i][j]=nw++;
        i++,j++;
        if(i>n || j>n)     i=1,j=n-(++k);
        while(j<1)  i++,j++;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
