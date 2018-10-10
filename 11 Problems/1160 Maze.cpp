#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
class b{
public:
    int x,y,d;
}tmp;
int a[155][155],mark[155][155],d[155][155][2],r,c,rs,cs,re,ce,cnt=0,Min=1<<20,f[4]={-1,1,0,0};
queue <b> q;
int main(){
    scanf("%d %d %d %d %d %d",&r,&c,&rs,&cs,&re,&ce);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            scanf("%d",&a[i][j]);
    if(!a[rs][cs])  a[rs][cs]=1;
    tmp.x=rs,tmp.y=cs,tmp.d=1;
    q.push(tmp);
    while(!q.empty()){
        b now=q.front();
        q.pop();
        if(mark[now.x][now.y])      continue;
        mark[now.x][now.y]=1,d[now.x][now.y][0]=now.d;
        if(!a[now.x][now.y])    continue;
        for(int i=0;i<4;i++){
            int newx=now.x+f[i],newy=now.y+f[3-i];
            if(newx>0 && newy>0 && newx<=r && newy<=c){
                tmp.x=newx,tmp.y=newy,tmp.d=now.d+1;
                q.push(tmp);
            }
        }
    }
    memset(mark,0,sizeof(mark));
    tmp.x=re,tmp.y=ce,tmp.d=1;
    q.push(tmp);
    while(!q.empty()){
        b now=q.front();
        q.pop();
        if(mark[now.x][now.y])      continue;
        mark[now.x][now.y]=1,d[now.x][now.y][1]=now.d;
        if(!a[now.x][now.y])    continue;
        for(int i=0;i<4;i++){
            int newx=now.x+f[i],newy=now.y+f[3-i];
            if(newx>0 && newy>0 && newx<=r && newy<=c){
                tmp.x=newx,tmp.y=newy,tmp.d=now.d+1;
                q.push(tmp);
            }
        }
    }
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++){
            if(!a[i][j] && d[i][j][0] && d[i][j][1]){
                cnt++,Min=min(Min,d[i][j][0]+d[i][j][1]-1);
            }
        }
    printf("%d\n%d\n",cnt,Min);
    return 0;
}
