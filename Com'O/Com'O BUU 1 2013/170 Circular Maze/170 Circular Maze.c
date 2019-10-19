#include<stdio.h>
#include<string.h>
int q[10010][2],b[110][110],r,c,state;
char a[110][110];
void play(int i,int j){
    a[i][j]='x';
    if(i<0)     i=r-1;
    if(i>r-1)   i=0;
    if(j<0)     j=c-1;
    if(j>c-1)   j=0;
    if(i>0 && b[i-1][j]==state-1)
        play(i-1,j);
}
int main(){
    int i,j,nowi,nowj,stri,strj,endi,endj,front=0,rear=1;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='S')
                stri=i,strj=j;
            if(a[i][j]=='E')
                endi=i,endj=j;
        }
    q[0][0]=stri,a[0][1]=strj;
    memset(b,-1,sizeof(b));
    b[stri][strj]=0;
    while(front<rear){
        nowi=q[front][0],nowj=q[front][1];
        state=b[nowi][nowj];
        if(nowi==0)     nowi=r-1;
        if(nowi==r-1)   nowi=0;
        if(nowj==0)     nowj=c-1;
        if(nowj==c-1)   nowj=0;
        if(nowi==endi && nowj==endj){
            play(nowi,nowj);
            break;
        }
        if(nowi>0 && a[nowi-1][nowj]!='#' && b[nowi-1][nowj]==-1){
            q[rear][0]=nowi-1,q[rear][1]=nowj;
            b[nowi-1][nowj]=state+1;    rear++;
        }
        if(nowj>0 && a[nowi][nowj-1]!='#' && b[nowi][nowj-1]==-1){
            q[rear][0]=nowi,q[rear][1]=nowj-1;
            b[nowi][nowj-1]=state+1;    rear++;
        }
        if(nowi<r-1 && a[nowi+1][nowj]!='#' && b[nowi+1][nowj]==-1){
            q[rear][0]=nowi+1,q[rear][1]=nowj;
            b[nowi+1][nowj]=state+1;    rear++;
        }
        if(nowj<c-1 && a[nowi][nowj+1]!='#' && b[nowi][nowj+1]==-1){
            q[rear][0]=nowi,q[rear][1]=nowj+1;
            b[nowi][nowj+1]=state+1;    rear++;
        }
        front++;
    }
    for(i=0;i<r;i++)
        printf("%s\n",a[i]);
    return 0;
}
