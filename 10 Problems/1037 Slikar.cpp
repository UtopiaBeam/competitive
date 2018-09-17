#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> coor;
typedef pair<coor,int> state;
queue <state> q;
char a[55][55];
int r,c,stri,strj,endi,endj,mark[55][55],b[2505][55][55],Min=1<<20,debug[55][55];
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)
        scanf(" %s",a[i]);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            b[0][i][j]=1<<20,debug[i][j]=1<<20;
            if(a[i][j]=='*')    b[0][i][j]=0;
            if(a[i][j]=='D')    endi=i,endj=j;
            if(a[i][j]=='S')    stri=i,strj=j,debug[i][j]=0;
        }
    for(int k=1;k<r*c;k++){
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                b[k][i][j]=b[k-1][i][j];
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(b[k][i][j]==k-1){
                    if(i>0 && a[i-1][j]!='D' && a[i-1][j]!='X' && k<b[k][i-1][j])     b[k][i-1][j]=k;
                    if(i<r-1 && a[i+1][j]!='D' && a[i+1][j]!='X' && k<b[k][i+1][j])   b[k][i+1][j]=k;
                    if(j>0 && a[i][j-1]!='D' && a[i][j-1]!='X' && k<b[k][i][j-1])     b[k][i][j-1]=k;
                    if(j<c-1 && a[i][j+1]!='D' && a[i][j+1]!='X' && k<b[k][i][j+1])   b[k][i][j+1]=k;
                }
    }
    q.push(state(coor(stri,strj),0));
    while(!q.empty()){
        int i=((q.front()).first).first,j=((q.front()).first).second,now=(q.front()).second;
        q.pop();
        if(mark[i][j])      continue;
        if(i==endi && j==endj){
            if(Min>now)     Min=now;
        }
        else{
            mark[i][j]=1,debug[i][j]=now;
            if(i>0 && a[i-1][j]!='X' && b[now+1][i-1][j]>now+1 && !mark[i-1][j])
                q.push(state(coor(i-1,j),now+1));
            if(i<r-1 && a[i+1][j]!='X' && b[now+1][i+1][j]>now+1 && !mark[i+1][j])
                q.push(state(coor(i+1,j),now+1));
            if(j>0 && a[i][j-1]!='X' && b[now+1][i][j-1]>now+1 && !mark[i][j-1])
                q.push(state(coor(i,j-1),now+1));
            if(j<c-1 && a[i][j+1]!='X' && b[now+1][i][j+1]>now+1 && !mark[i][j+1])
                q.push(state(coor(i,j+1),now+1));
        }
    }
    if(Min==1<<20)      printf("KAKTUS\n");
    else    printf("%d\n",Min);
    return 0;
}
