#include<cstdio>
#include<vector>
#include<algorithm>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int n,m,t,a[102][102],pr[102],pb[102],nw[102],cnt=0,vp[102][102],d;
vector<int> vb[102];
vector<P> vt[102];
int main(){
    //Initial
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            scanf("%d",&t);
            if(t){
                a[i][t]=j;
                vb[i].push_back(t);
                vt[t].push_back(P(-j,i));
            }
        }
    for(int i=1;i<=n;i++)
        sort(vt[i].begin(),vt[i].end());
    for(int i=1;i<=n;i++)
        for(int j=0;j<vt[i].size();j++)
            vp[i][vt[i][j].S]=j;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%d ",vp[i][j]+1);
        printf("\n");
    }
    //Stable Marriage
    while(cnt<n){
        for(int i=1;i<=n;i++){
            if(!pb[i]){
                d=vb[i][nw[i]];
                if(!pr[d])
            }
        }
    }
    return 0;
}
