#include<cstdio>
#include<queue>
using namespace std;
int r,c,b[105][105];
char a[105][105];
class Q{
public:
    int nx,ny,cnt;
}tmp;
queue<Q> q;
int main(){
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            scanf(" %c",&a[i][j]);
    tmp.nx=1,tmp.ny=1,tmp.cnt=1;
    q.push(tmp);
    while(!q.empty()){
        int x=q.front().nx,y=q.front().ny,d=q.front().cnt;
        q.pop();
        if(b[x][y]){
            if(b[x][y]==d-2)    continue;
            printf("%d\n%d %d\n",d,x,y);
            return 0;
        }
        b[x][y]=d;
        if(x<r && (a[x][y]=='B' || a[x][y]=='D')){
            tmp.nx=x+1,tmp.ny=y,tmp.cnt=d+1;
            q.push(tmp);
        }
        if(y<c && (a[x][y]=='B' || a[x][y]=='R')){
            tmp.nx=x,tmp.ny=y+1,tmp.cnt=d+1;
            q.push(tmp);
        }
        if(x>1 && (a[x-1][y]=='B' || a[x-1][y]=='D')){
            tmp.nx=x-1,tmp.ny=y,tmp.cnt=d+1;
            q.push(tmp);
        }
        if(y>0 && (a[x][y-1]=='B' || a[x][y-1]=='R')){
            tmp.nx=x,tmp.ny=y-1,tmp.cnt=d+1;
            q.push(tmp);
        }
    }
}
