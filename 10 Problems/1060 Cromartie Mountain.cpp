#include<stdio.h>
#include<string.h>
char a[15][85];
int main(){
    memset(a,'.',sizeof(a));
    int n,maxs=0,maxh=0;
    scanf("%d",&n);
    while(n--){
        int s,h;
        scanf("%d %d",&s,&h);
        if(maxh<h)  maxh=h;
        if(maxs<s+2*h-1)  maxs=s+2*h-1;
        for(int i=1;i<=h;i++){
            for(int j=s;j<s+h;j++){
                if(i-1==j-s){
                    if(a[i][j]=='.')    a[i][j]='/';
                    else if(a[i][j]=='\\')  a[i][j]='v';
                }
                else if(i-1<j-s)
                    a[i][j]='X';
            }
        }
        for(int i=h;i>0;i--){
            for(int j=s+h;j<s+2*h;j++){
                if(i+j==s+2*h){
                    if(a[i][j]=='.')    a[i][j]='\\';
                    else if(a[i][j]=='/')  a[i][j]='v';
                }
                else if(i+j<s+2*h)
                    a[i][j]='X';
            }
        }
    }
    for(int i=maxh;i>0;i--){
        for(int j=1;j<=maxs;j++)
            printf("%c",a[i][j]);
        printf("\n");
    }
    return 0;
}
