#include<cstdio>
int r,c,cnt=0,s[4]={-1,1,0,0};
char a[1002][82];
void f(int i,int j){
    if(a[i][j]=='.')   return ;
    a[i][j]='.';
    for(int k=0;k<4;k++)
        f((i+s[k]+r)%r,(j+s[3-k]+c)%c);
}
int main(){
    scanf("%d %d",&c,&r);
    for(int i=0;i<r;i++)    scanf(" %s",a[i]);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            if(a[i][j]=='*'){
                f(i,j);     cnt++;
            }
        }
    printf("%d\n",cnt);
    return 0;
}
