#include<cstdio>
#include<queue>
using namespace std;
#define P pair<int,int>
#define F first
#define S second
queue<P> q;
int r,c,b[32][32],s[4]={-1,1,0,0};
char a[32][32];
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)    scanf(" %s",a[i]);
    for(int j=0;j<c-1;j++){
        if(a[0][j]!='#' && a[0][j+1]!='#' && a[1][j]!='#' && a[1][j+1]!='#'){
            q.push(P(0,j));
            while(!q.empty()){
                int x=q.front().F,y=q.front().S;
                if(x==r-2){
                    printf("yes\n");    return 0;
                }
                b[x][y]=1;
                for(int k=0;k<4;k++){
                    int nx=x+s[k],ny=y+s[3-k];
                    if(nx>=0 && ny>=0 && nx<r-1 && ny<c-1 && !b[nx][ny] && a[nx][ny]!='#' && a[nx+1][ny]!='#'
                       && a[nx][ny+1]!='#' && a[nx+1][ny+1]!='#')
                        q.push(P(nx,ny));
                }
            }
        }
    }
    printf("no\n");
    return 0;
}
