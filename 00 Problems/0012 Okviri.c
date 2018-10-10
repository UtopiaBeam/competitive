#include<stdio.h>
#include<string.h>
int main(){
    int len,i,j,k=0;
    char a[30],b[10][80];
    gets(a);    len=strlen(a);
    for(i=1;i<=5;i++)
        for(j=1;j<=4*len+1;j++)
            b[i][j]='.';
    for(i=3;i<=4*len+1;i+=4){
        b[3][i]=a[i/4];
        if((i/4)%3!=2){
            b[1][i]=b[2][i-1]=b[2][i+1]=b[4][i-1]=b[4][i+1]=b[5][i]='#';
            if(b[3][i-2]!='*')      b[3][i-2]='#';
            if(b[3][i+2]!='*')      b[3][i+2]='#';
        }
        else{
            b[1][i]=b[2][i-1]=b[2][i+1]=b[3][i-2]=b[3][i+2]=b[4][i-1]=b[4][i+1]=b[5][i]='*';
        }
    }
    for(i=1;i<=5;i++){
        for(j=1;j<=4*len+1;j++)
            printf("%c",b[i][j]);
        printf("\n");
    }
    return 0;
}
