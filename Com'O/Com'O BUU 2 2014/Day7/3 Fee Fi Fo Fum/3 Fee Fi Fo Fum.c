#include<stdio.h>
#include<string.h>
int r,c,b[1010][1010],q[1000010][2];
char a[1010][1010];
int main(){
    int i,j,front=0,rear=1,stri,strj,endi,endj,nowi,nowj,state;
    char ch;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='S')    stri=i,strj=j;
            if(a[i][j]=='E')    endi=i,endj=j;
        }
    memset(b,-1,sizeof(b));
    q[0][0]=stri,q[0][1]=strj;
    b[stri][strj]=0;
    while(front<rear){
        //Dequeue
        nowi=q[front][0],nowj=q[front][1];
        state=b[nowi][nowj];
        if(nowi==endi && nowj==endj){
            printf("%d\n",state);
            return 0;
        }
        //Enqueue
        if(nowi>0 && b[nowi-1][nowj]==-1 && a[nowi-1][nowj]!='#'){
            q[rear][0]=nowi-1,q[rear][1]=nowj;
            b[nowi-1][nowj]=state+1,rear++;
        }
        if(nowj>0 && b[nowi][nowj-1]==-1 && a[nowi][nowj-1]!='#'){
            q[rear][0]=nowi,q[rear][1]=nowj-1;
            b[nowi][nowj-1]=state+1,rear++;
        }
        if(nowi+1<r && b[nowi+1][nowj]==-1 && a[nowi+1][nowj]!='#'){
            q[rear][0]=nowi+1,q[rear][1]=nowj;
            b[nowi+1][nowj]=state+1,rear++;
        }
        if(nowj+1<c && b[nowi][nowj+1]==-1 && a[nowi][nowj+1]!='#'){
            q[rear][0]=nowi,q[rear][1]=nowj+1;
            b[nowi][nowj+1]=state+1,rear++;
        }
        front++;
    }
    printf("-1\n");
    return 0;
}
