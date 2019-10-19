#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct S{
    int x,y,w;
    S(int x=0,int y=0,int w=0):
        x(x),y(y),w(w){}
    bool operator<(const S &a)const{
        return w > a.w;
    }
};
int n,a[1002][1002],sx=-1,sy,ex,ey,d[1002][1002],s[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
priority_queue<S> q;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            d[i][j]=1e9;
            scanf("%d",&a[i][j]);
            if(a[i][j]==0){
                if(sx<0)    sx=i,sy=j;
                else        ex=i,ey=j;
            }
        }
    q.push(S(sx,sy,0));
    while(!q.empty()){
        int x=q.top().x,y=q.top().y,w=q.top().w;
        q.pop();
        if(x==ex && y==ey){
            printf("%d\n",w);
            return 0;
        }
        for(int i=0;i<4;i++){
            int nx=x+s[i][0],ny=y+s[i][1];
            if(nx<0 || ny<0 || nx>=n || ny>=n || d[nx][ny]<=max(w,a[nx][ny]))
                continue;
            d[nx][ny]=max(w,a[nx][ny]);
            q.push(S(nx,ny,max(w,a[nx][ny])));
        }
    }
    return 0;
}
