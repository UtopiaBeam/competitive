#include<cstdio>
#include<queue>
using namespace std;
struct S{
    int t,x,y;
    S(int t=0,int x=0,int y=0):
        t(t),x(x),y(y){}
    bool operator<(const S &a)const{
        return t>a.t;
    }
}nw;
priority_queue<S> q;
int qr,n,r,c,T,t[102],x[102],y[102],nx,ny;
int s[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char a[102][102];
bool f(int x,int y){
    return (x>=0 &&& y>=0 && x<r && y<c);
}
int main(){
    scanf("%d",&qr);
    while(qr--){
        scanf("%d %d %d %d %d %d",&r,&c,&n,&T,x,y);
        q.push(S(1,x[0],y[0]));
        for(int i=0;i<n;i++)
            scanf("%d %d %d",t+i,x+i,y+i);
        for(int i=0;i<r;i++)
            scanf(" %s",a[i]);
        while(!q.empty()){
            nw=q.top();
            q.pop();
            if(!f(nw.x,nw.y) || a[nw.x][nw.y]!='.')
                continue;
            a[nw.x][nw.y]='x';
            for(int i=0;i<4 && nw.t<=T;i++){
                nx=nw.x+s[i][0],ny=nw.y+s[i][1];
                if(f(nx,ny) && a[nx][ny]=='.')
                    q.push(S(nw.t+1,nx,ny));
            }
        }
        for(int i=0;i<n;i++)
            q.push(S(t[i],x[i],y[i]));
        while(!q.empty()){
            nw=q.top();
            q.pop();
            if(nw.t==T)     a[nw.x][nw.y]='*';
            if(!f(nw.x,nw.y) || a[nw.x][nw.y]=='#' || a[nw.x][nw.y]=='*')
                continue;
            a[nw.x][nw.y]='*';
            for(int i=0;i<4 && nw.t<=T;i++){
                nx=nw.x+s[i][0],ny=nw.y+s[i][1];
                if(f(nx,ny) && a[nx][ny]!='#' && a[nx][ny]!='*')
                    q.push(S(nw.t+1,nx,ny));
            }
        }
        bool chk=false;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(a[i][j]=='x')
                    chk=true;
        if(chk)     printf("YES\n");
        else        printf("NO\n");
    }
    return 0;
}
