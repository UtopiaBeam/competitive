#include<cstdio>
#include<queue>
using namespace std;
struct S{
    int x,y,h;
    S(int x=0,int y=0,int h=0):
        x(x),y(y),h(h){}
    bool operator<(const S &a)const{
        return h > a.h;
    }
};
queue<S> q;
priority_queue<S> hp;
int t,r,c,a[102][102],b[102][102],s[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int main(){
    scanf("%d",&t);
    while(t--){
        int ans=0;
        scanf("%d %d",&r,&c);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++){
                b[i][j]=0;
                scanf("%d",&a[i][j]);
                if(i==0 || j==0 || i==r-1 || j==c-1)
                    hp.push(S(i,j,a[i][j]));
            }
        while(!hp.empty()){
            int H=hp.top().h;
            q.push(hp.top());
            hp.pop();
            while(!q.empty()){
                int x=q.front().x,y=q.front().y,h=q.front().h;
                q.pop();
                if(b[x][y])     continue;
                b[x][y]=1;      ans+=H-h;
                for(int i=0;i<4;i++){
                    int nx=x+s[i][0],ny=y+s[i][1];
                    if(nx<0 || ny<0 || nx>=r || ny>=c || b[nx][ny])
                        continue;
                    if(a[nx][ny]>=H)     hp.push(S(nx,ny,a[nx][ny]));
                    else    q.push(S(nx,ny,a[nx][ny]));
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
