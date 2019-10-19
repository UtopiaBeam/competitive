#include<cstdio>
char a[10][10];
int r,c,k,cnt=0;
void f(int i,int j,int d){
    if(i<0 || j<0 || i>=r || j>=c || a[i][j]!='.')  return ;
    if(i==r-1 && j==c-1){
        cnt+=(d==k);    return ;
    }
    a[i][j]='x';
    int s[4]={-1,1,0,0};
    for(int k=0;k<4;k++)
        f(i+s[k],j+s[3-k],d+1);
    a[i][j]='.';
}
int main(){
    scanf("%d %d %d",&r,&c,&k);
    for(int i=r-1;i>=0;i--) scanf(" %s",a[i]);
    f(0,0,1);
    printf("%d\n",cnt);
    return 0;
}
