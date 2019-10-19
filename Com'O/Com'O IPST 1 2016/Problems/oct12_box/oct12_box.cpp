#include<cstdio>
int r,c,chk=0,s[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char a[32][32];
bool f(int i,int j){
    return (i>=0 && j>=0 && i<r-1 && j<c-1 &&
            a[i][j]=='.' && a[i+1][j]!='#' && a[i][j+1]!='#' && a[i+1][j+1]!='#');
}
void debug(){
    printf("\n");
    for(int i=0;i<r;i++)
        printf("%s\n",a[i]);
}
void dfs(int i,int j){
    if(a[i][j]=='x' || !f(i,j))    return ;
    if(i==r-2){
        chk=1;      return ;
    }
    a[i][j]='x';
//    debug();
    for(int k=0;k<4;k++){
        int ni=i+s[k][0],nj=j+s[k][1];
        if(f(ni,nj))    dfs(ni,nj);
    }
    a[i][j]='.';
}
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)
        scanf(" %s",a[i]);
    for(int j=0;j<c-1;j++)
        if(f(0,j)){
            dfs(0,j);
            if(chk){
                printf("yes\n");
                return 0;
            }
        }
    printf("no\n");
    return 0;
}
