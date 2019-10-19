#include<cstdio>
#include<queue>
using namespace std;
int r,c,n,b[305][305],d[305][305],x,y,cx[8]={-1,-1,-1,0,1,1,1,0},cy[8]={-1,0,1,1,1,0,-1,-1};
char a[305][305];
class sta{
public:
    int sx,sy,ex,ey,cnt;
}now,tmp;
queue<sta> q;
int main(){
    scanf("%d %d %d",&r,&c,&n);
    for(int i=0;i<r;i++)
        scanf(" %s",a[i]);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            b[i][j]=1<<20;
            if(a[i][j]=='J'){
                now.sx=-1,now.sy=-1,now.ex=i,now.ey=j,now.cnt=0;
                q.push(now);
            }
        }
    while(!q.empty()){
        now=q.front();
        q.pop();
        d[now.ex][now.ey]=1;
        if(b[now.ex][now.ey]>now.cnt)   b[now.ex][now.ey]=now.cnt;
        tmp.sx=now.ex,tmp.sy=now.ey;
        for(int i=0;i<8;i++){
            tmp.ex=now.ex+cx[i],tmp.ey=now.ey+cy[i];
            if(d[tmp.ex][tmp.ey] || tmp.ex<0 || tmp.ey<0 || tmp.ex>=r || tmp.ey>=c || a[tmp.ex][tmp.ey]=='#')   continue;
            if(now.sx>=0 && now.sy>=0){
                if(now.sx-now.ex!=tmp.sx-tmp.ex || now.sy-now.ey!=tmp.sy-tmp.ey)
                    tmp.cnt=now.cnt+1;
                else    tmp.cnt=now.cnt;
            }
            q.push(tmp);
        }
    }
    while(n--){
        scanf("%d %d",&x,&y);
        if(b[x][y]!=1<<20)  printf("%d\n",b[x][y]);
        else    printf("-1\n");
    }
    return 0;
}
