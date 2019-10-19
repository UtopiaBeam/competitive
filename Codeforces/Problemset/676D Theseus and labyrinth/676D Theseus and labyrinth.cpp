#include<cstdio>
#include<queue>
using namespace std;
struct S{
    int x,y,d,p;
    S(int x=0,int y=0,int d=0,int p=0):
        x(x),y(y),d(d),p(p){}
};
queue<S> q;
int r,c,sx,sy,ex,ey;
char a[1002][1002];
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)
        scanf(" %s",a[i]);
    scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
    q.push(S(sx,sy));
    while(!q.empty()){
        int x=q.front().x,y=q.front().y,d=q.front().d,p=q.front().p;
        q.pop();
        if(a[x][y]=='*' || b[x][y])
            continue;
        b[x][y]=1;
    }
}
