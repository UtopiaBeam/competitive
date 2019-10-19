#include<cstdio>
#include<vector>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int n,t;
int a[20][20],b[20][20],c[20][20];
int s[5][2]={{0,0},{-1,0},{1,0},{0,-1},{0,1}};
vector<P> ans;
void reset(){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            b[i][j]=a[i][j];
            c[i][j]=0;
        }
}
void press(int x,int y){
    c[x][y]^=1;
    for(int i=0;i<5;i++){
        int nx=x+s[i][0],ny=y+s[i][1];
        if(nx>=0 && ny>=0 && nx<n && ny<n)
            b[nx][ny]^=1;
    }
}
void lightChase(){
    for(int i=1;i<n;i++)
        for(int j=0;j<n;j++)
            if(b[i-1][j])       press(i,j);
}
bool isAllOff(){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(b[i][j])     return false;
    return true;
}
void getAns(){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(c[i][j])     ans.push_back(P(i+1,j+1));
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d %d\n",ans[i].F,ans[i].S);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            scanf("%d",&t);
            a[i][j]^=t;
        }
    for(int i=0;i<(1<<n);i++){
        reset();
        //Press the first row
        for(int j=0;j<n;j++){
            if((i>>j)&1)
                press(0,j);
        }
        lightChase();
        if(isAllOff()){
            getAns();
            return 0;
        }
    }
}
