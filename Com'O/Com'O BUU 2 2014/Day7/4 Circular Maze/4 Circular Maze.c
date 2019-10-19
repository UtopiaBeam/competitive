//BFS
#include<stdio.h>
#include<string.h>
int q[10010][2],b[110][110],r,c,state;
char a[110][110];
void play(int i,int j){
    if(state==0)      return ;
    state--;
    if(a[i][j]!='E')    a[i][j]='x';
    if(i==0 && b[r-1][j]==state)    play(r-1,j);
    else if(b[i-1][j]==state)       play(i-1,j);
    if(i==r-1 && b[0][j]==state)    play(0,j);
    else if(b[i+1][j]==state)       play(i+1,j);
    if(j==0 && b[i][c-1]==state)    play(i,c-1);
    else if(b[i][j-1]==state)       play(i,j-1);
    if(j==c-1 && b[i][0]==state)    play(i,0);
    else if(b[i][j+1]==state)       play(i,j+1);
}
int main(){
    int i,j,stri,strj,endi,endj,nowi,nowj,front=0,rear=1;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='S')    stri=i,strj=j;
            if(a[i][j]=='E')    endi=i,endj=j;
        }
    q[0][0]=stri,q[0][1]=strj;
    memset(b,-1,sizeof(b));
    b[stri][strj]=0;
    while(front<rear){
        nowi=q[front][0],nowj=q[front][1];
        state=b[nowi][nowj];
        for(i=0;i<r;i++){
            for(j=0;j<c;j++)
                printf((b[i][j]<0)? "%d":" %d",b[i][j]);
            printf("\n");
        }
        printf("%d %d\n",nowi,nowj);
        if(nowi==endi && nowj==endj){
            play(nowi,nowj);
            break;
        }
        if(nowi>0 && b[nowi-1][nowj]==-1 && a[nowi-1][nowj]!='#'){
            q[rear][0]=nowi-1,q[rear][1]=nowj;
            b[nowi-1][nowj]=state+1;    rear++;
        }
        else if(nowi==0 && b[r-1][nowj]==-1 && a[r-1][nowj]!='#'){
            q[rear][0]=r-1,q[rear][1]=nowj;
            b[r-1][nowj]=state+1;   rear++;
        }
        if(nowj>0 && b[nowi][nowj-1]==-1 && a[nowi][nowj-1]!='#'){
            q[rear][0]=nowi,q[rear][1]=nowj-1;
            b[nowi][nowj-1]=state+1;    rear++;
        }
        else if(nowj==0 && b[nowi][c-1]==-1 && a[nowi][c-1]!='#'){
            q[rear][0]=nowi,q[rear][1]=c-1;
            b[nowi][c-1]=state+1;       rear++;
        }
        if(nowi<r-1 && b[nowi+1][nowj]==-1 && a[nowi+1][nowj]!='#'){
            q[rear][0]=nowi+1,q[rear][1]=nowj;
            b[nowi+1][nowj]=state+1;    rear++;
        }
        else if(nowi==r-1 && b[0][nowj]==-1 && a[0][nowj]!='#'){
            q[rear][0]=0,q[rear][1]=nowj;
            b[0][nowj]=state+1;     rear++;
        }
        if(nowj<c-1 && b[nowi][nowj+1]==-1 && a[nowi][nowj+1]!='#'){
            q[rear][0]=nowi,q[rear][1]=nowj+1;
            b[nowi][nowj+1]=state+1;    rear++;
        }
        else if(nowj==c-1 && b[nowi][0]==-1 && a[nowi][0]!='#'){
            q[rear][0]=nowi,q[rear][1]=0;
            b[nowi][0]=state+1;     rear++;
        }
        front++;
    }
    for(i=0;i<r;i++)
        printf("%s\n",a[i]);
    return 0;
}
