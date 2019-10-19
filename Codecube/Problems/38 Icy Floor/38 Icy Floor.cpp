#include<cstdio>
#include<queue>
using namespace std;
class C{
public:
    int i,j,d;
}nw,nx;
queue<C> q;
int n,a[1002][1002],si[4]={-1,0,1,0},sj[4]={0,-1,0,1};
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    nw.i=0,nw.j=0;
    for(int i=0;i<4;i++)    nw.d=i,q.push(nw);
    while(!q.empty()){
        nw=q.front();   q.pop();
        nx.i=nw.i+si[nw.d],nx.j=nw.j+sj[nw.d];
        if(nx.i<0 || nx.j<0 || a[nx.i][nx.j]);
    }
    return 0;
}
