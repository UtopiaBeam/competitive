#include<cstdio>
#include<queue>
using namespace std;
int r,c,a[1002][1002],b[]={-1,1,0,0},cnt=0;
class P{
public:
    int x,y,d;
}nw,nx;
queue<P> q;
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(a[i][j]==0){
                nw.x=i,nw.y=j,nw.d=0;
                q.push(nw);
            }
    while(!q.empty()){
        nw=q.front();
        q.pop();
        if(a[nw.x][nw.y]>=nw.d){
            nx.d=nw.d+1,a[nw.x][nw.y]=-1;
            for(int k=0;k<4;k++){
                nx.x=nw.x+b[k],nx.y=nw.y+b[3-k];
                if(nx.x>=0 && nx.x<r && nx.y>=0 && nx.y<c && a[nx.x][nx.y]>nx.d)
                    q.push(nx);
            }
        }
    }
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(a[i][j]>0)   cnt++;
    printf("%d\n",cnt);
    return 0;
}
