#include<stdio.h>
int main(){
    int i,j,r,c,a[120][120];
    char ch;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            scanf(" %c",&ch);
            if(ch=='.')     a[i][j]=2;
            if(ch=='+')     a[i][j]=1;
        }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(a[i][j]==2)     a[i][j]=0;
            if(a[i][j]==1)     break;
        }
    }
    for(i=0;i<r;i++){
        for(j=c-1;j>=0;j--){
            if(a[i][j]==2)     a[i][j]=0;
            if(a[i][j]==1)     break;
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(a[i][j]==0)  printf(".");
            if(a[i][j]==1)  printf("+");
            if(a[i][j]==2)  printf("#");
        }
        printf("\n");
    }
    return 0;
}
