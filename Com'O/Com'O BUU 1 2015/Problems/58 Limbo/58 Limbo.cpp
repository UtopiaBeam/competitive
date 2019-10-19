#include<cstdio>
int r,c,b[1002][82],cnt,mx=0,s[4]={-1,1,0,0};
char a[1002][82];
void f(int i,int j){
    if(i<0 || j<0 || i>=r || j>=c || b[i][j] || a[i][j]=='.')   return ;
    b[i][j]=1,cnt++;
    for(int k=0;k<4;k++)    f(i+s[k],j+s[3-k]);
}
int main(){
    scanf("%d %d",&c,&r);
    for(int i=0;i<r;i++)    scanf(" %s",a[i]);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            cnt=0;
            if(!b[i][j] && a[i][j]=='*'){
                f(i,j);
                if(mx<cnt)  mx=cnt;
            }
        }
    printf("%d\n",mx);
    return 0;
}
