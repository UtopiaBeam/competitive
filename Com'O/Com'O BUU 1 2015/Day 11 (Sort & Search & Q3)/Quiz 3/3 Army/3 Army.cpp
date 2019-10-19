#include<cstdio>
#include<stack>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
stack<P> s;
int r,c,cnt=0,mx=0;
char a[752][752];
void dfs(){
    int si[8]={-1,-1,-1,0,1,1,1,0},sj[8]={-1,0,1,1,1,0,-1,-1};
    cnt=0;
    while(!s.empty()){
        int i=s.top().F,j=s.top().S;
        s.pop(),cnt++,a[i][j]='*';
        for(int k=0;k<8;k++){
            int ni=i+si[k],nj=j+sj[k];
            if(ni>=0 && nj>=0 && ni<r && nj<c && a[ni][nj]=='.')    s.push(P(ni,nj));
        }
    }
    if(mx<cnt)  mx=cnt;
}
int main(){
    scanf("%d %d",&c,&r);
    for(int i=0;i<r;i++)    scanf(" %s",a[i]);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(a[i][j]=='.'){
                s.push(P(i,j));     dfs();
                printf("%d\n",cnt);
            }
    printf("%d\n",mx);
    return 0;
}
