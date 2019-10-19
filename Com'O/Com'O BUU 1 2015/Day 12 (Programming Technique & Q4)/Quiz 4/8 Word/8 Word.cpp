#include<cstdio>
#include<cctype>
int r,c,x,y,n,si[8]={-1,-1,-1,0,1,1,1,0},sj[8]={-1,0,1,1,1,0,-1,-1},chk;
char a[30][30],w[20];
void f(int i,int j,int k,int l){
    if(w[l+1]=='\0'){
        printf("%d %d\n",x,y);  chk=0;
        return ;
    }
    int ni=i+si[k],nj=j+sj[k];
    if(ni>=0 && nj>=0 && ni<r && nj<c && w[l+1]==a[ni][nj])
        f(ni,nj,k,l+1);
}
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)    scanf(" %s",a[i]);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            a[i][j]=tolower(a[i][j]);
    scanf("%d",&n);
    while(n--){
        chk=1;
        scanf(" %s",w);
        for(int i=0;w[i];i++)   w[i]=tolower(w[i]);
        for(int i=0;i<r && chk;i++)
            for(int j=0;j<c && chk;j++){
                x=i,y=j;
                for(int k=0;k<8;k++)    f(i,j,k,0);
            }
    }
    return 0;
}
