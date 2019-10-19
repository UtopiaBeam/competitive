#include<cstdio>
char s[8];
int n,a[22][22],si[4]={0,0,1,-1},sj[4]={1,-1,0,0},in,chk;
void shift(int i,int j){
    for(int x=i,y=j;x>0 && x<=n && y>0 && y<=n;x+=si[in],y+=sj[in])   a[x][y]=a[x+si[in]][y+sj[in]];
}
void f(int &i,int &j,int &chk){
    if(a[i][j]==0){
        if(chk) shift(i,j),i+=si[in],j+=sj[in];
    }
    else    chk=1;
}
void g(int &i,int &j){
    if(a[i][j] && a[i][j]==a[i+si[in]][j+sj[in]])
        a[i][j]*=2,a[i+si[in]][j+sj[in]]=0,shift(i+si[in],j+sj[in]);
}
int main(){
    scanf("%d %s",&n,s);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    if(s[0]=='l'){
        in=0;
        for(int i=1;i<=n;i++){
            chk=0;
            for(int j=n;j>0;j--)    f(i,j,chk);
            for(int j=1;j<=n;j++)   g(i,j);
        }
    }
    if(s[0]=='r'){
        in=1;
        for(int i=1;i<=n;i++){
            chk=0;
            for(int j=1;j<=n;j++)   f(i,j,chk);
            for(int j=n;j>0;j--)    g(i,j);
        }
    }
    if(s[0]=='u'){
        in=2;
        for(int j=1;j<=n;j++){
            chk=0;
            for(int i=n;i>0;i--)    f(i,j,chk);
            for(int i=1;i<=n;i++)   g(i,j);
        }
    }
    if(s[0]=='d'){
        in=3;
        for(int j=1;j<=n;j++){
            chk=0;
            for(int i=1;i<=n;i++)    f(i,j,chk);
            for(int i=n;i>0;i--)   g(i,j);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
