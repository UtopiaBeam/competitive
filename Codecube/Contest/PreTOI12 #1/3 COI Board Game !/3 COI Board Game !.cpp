#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct S{
    int x,y,cnt,t;
}nw;
int s[4][2]={{-1,0},{1,0},{0,-1},{0,1}},r,c,b[502][502][8];
char a[502][502];
queue<S> q;
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)
        scanf(" %s",a[i]);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            for(int k=0;k<8;k++)
                b[i][j][k]=1<<30;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(a[i][j]=='S'){
                nw.x=i,nw.y=j,nw.cnt=0,nw.t=0;
                q.push(nw);
                break;
            }
    while(!q.empty()){
        nw=q.front();
        q.pop();
        int x=nw.x,y=nw.y,cnt=nw.cnt,t=nw.t;
        if(x<0 || x>=r || y<0 || y>=c || a[x][y]=='#')
            continue;
        if(b[x][y][t]<=cnt)
            continue;
        if(a[x][y]=='J' && t%2==0)          continue;
        if(a[x][y]=='B' && (t>>1)%2==0)     continue;
        if(a[x][y]=='P' && (t>>2)%2==0)     continue;
        if(a[x][y]=='E'){
            printf("%d\n",cnt);
            return 0;
        }
        if(a[x][y]=='j')      t|=1;
        if(a[x][y]=='b')      t|=1<<1;
        if(a[x][y]=='p')      t|=1<<2;
        b[x][y][t]=cnt;
        for(int i=0;i<4;i++){
            int nx=x+s[i][0],ny=y+s[i][1];
            if(nx<0 || nx>=r || ny<0 || ny>=c || a[nx][ny]=='#')
                continue;
            if(b[nx][ny][t]<=cnt+1)
                continue;
            if(a[nx][ny]=='J' && t%2==0)        continue;
            if(a[nx][ny]=='B' && (t>>1)%2==0)   continue;
            if(a[nx][ny]=='P' && (t>>2)%2==0)   continue;
            nw.x=nx,nw.y=ny,nw.cnt=cnt+1,nw.t=t;
            q.push(nw);
        }
    }
    printf("-1\n");
    return 0;
}
