#include<cstdio>
#include<cstring>
int r,c,k,t[102],nt=0,si[]={-1,0,1,0},sj[]={0,-1,0,1},cnt=0;
char a[12][12];
bool chk(int i,int j){
    return (i>=0 && j>=0 && i<r && j<c && a[i][j]==' ');
}
void f(int i,int j,int d){
    a[i][j]='o';
    int p=0;
    while(p<4){
        if(chk(i+si[p],j+sj[p])){
            if(d+1==t[nt]){
                a[i+si[p]][j+sj[p]]='x',nt++;
                f(i,j,d+1);
            }
            else    f(i+si[p],j+sj[p],d+1);
            break;
        }
        p++;
    }
    if(p==4)    a[i][j]='h';
}
int main(){
    memset(a,' ',sizeof(a));
    scanf("%d %d %d",&r,&c,&k);
    for(int i=0;i<k;i++)    scanf("%d",&t[i]);
    f(r,c-1,0);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(a[i][j]=='o' || a[i][j]=='h')    cnt++;
    printf("%d\n",cnt);
    for(int i=0;i<c;i++) printf("..");
    printf(".\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)    printf(".%c",a[i][j]);
        printf(".\n");
        for(int j=0;j<c;j++) printf("..");
        printf(".\n");
    }
    return 0;
}
