#include<cstdio>
#include<map>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int r,c,in,n,m,x,y,xt,yt,s[4][2]={{0,-1},{1,0},{0,1},{-1,0}},cnt=0;
char ch;
map<P,int> M;
int main(){
    scanf("%d %d",&c,&r);
    scanf("%d %d",&x,&y);
    scanf(" %c",&ch);
    if(ch=='N')     in=0;
    if(ch=='E')     in=1;
    if(ch=='S')     in=2;
    if(ch=='W')     in=3;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&xt,&yt);
        M[P(xt,yt)]++;
    }
    scanf("%d",&m);
    while(m--){
        scanf(" %c",&ch);
        if(ch=='L')         in=(in+3)%4;
        else if(ch=='R')    in=(in+1)%4;
        else{
            int nx,ny;
            if(ch=='F')
                nx=x+s[in][0],ny=y+s[in][1];
            else
                nx=x-s[in][0],ny=y-s[in][1];
            if(nx>0 && ny>0 && nx<=r && ny<=c)
                x=nx,y=ny;
        }
        if(M[P(x,y)]){
            M[P(x,y)]--;    cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
