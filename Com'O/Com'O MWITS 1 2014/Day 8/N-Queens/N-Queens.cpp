#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
char a[110][110];
int check(int r,int c){
    for(int i=0;i<n;i++)

}
void queen(int row){
    if(row==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                printf("%c",a[i][j]);
            printf("\n");
        }
        printf("----------------\n");
        return ;
    }
    for(int i=0;i<n;i++)
        if(check(row,i)){
            a[row][i]='Q';
            queen(row+1);
            a[row][i]='.';
        }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]='.';
    queen(0);
    return 0;
}
