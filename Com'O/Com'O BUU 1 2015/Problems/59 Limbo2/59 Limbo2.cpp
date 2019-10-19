#include<cstdio>
int r,c,b[82][82],cnt,mn=1<<30,s[4]={-1,1,0};
char a[82][82];
void f(int i,int j){
    if(i<0 || j<0 || i>=r || j>=c || b[i][j] || a[i][j]=='.')   return ;
    b[i][j]=1,cnt++;
    for(int k=0;k<3;k++)
        for(int l=0;l<3;l++)
            f(i+s[k],j+s[l]);
}
int main(){
    scanf("%d %d",&c,&r);
    for(int i=0;i<r;i++)    scanf(" %s",a[i]);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            cnt=0;
            if(!b[i][j] && a[i][j]=='*'){
                f(i,j);
                if(mn>cnt)  mn=cnt;
            }
        }
    printf("%d\n",mn);
    return 0;
}
