#include<cstdio>
#include<queue>
#define P pair<int,int>
#define PP pair<P,int>
#define F first
#define S second
using namespace std;
int r,c,a[502][502],b[1002],ans=0,lim=0,s[2]={0,1};
queue<PP> q;
int main(){
    scanf("%d %d",&r,&c);
    for(int i=r-1;i>=0;i--)
        for(int j=0;j<c;j++)
            scanf("%d",&a[i][j]);
    q.push(PP(P(0,0),0));
    while(!q.empty()){
        int x=q.front().F.F,y=q.front().F.S,d=q.front().S;
        q.pop();
        if(a[x][y])     continue;
        a[x][y]=1,b[d]++;
        if(lim<d)   lim=d;
        for(int i=0;i<2;i++){
            int nx=x+s[i],ny=y+s[1-i];
            if(nx<0 || nx>=r || ny<0 || ny>=c || a[nx][ny])   continue;
            q.push(PP(P(nx,ny),d+1));
        }
    }
    for(int i=0;i<=lim;i++)
        ans+=b[i]*b[i];
    printf("%d\n",ans);
    return 0;
}
