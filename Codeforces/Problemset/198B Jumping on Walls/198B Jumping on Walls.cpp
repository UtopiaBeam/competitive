#include<cstdio>
#include<queue>
using namespace std;
class X{
public:
    int lv,fld,wl;
}nw,nx;
queue<X> q;
int n,k,b[2][100005];
char a[2][100005];
int main(){
    scanf("%d %d ",&n,&k);
    gets(a[0]);     gets(a[1]);
    nx.lv=0,nx.fld=-1,nx.wl=0;
    q.push(nx);
    while(!q.empty()){
        nw=q.front();     q.pop();
        if(nw.lv>=n-1){
            printf("YES\n");       return 0;
        }
        if(b[nw.wl][nw.lv])     continue;
        b[nw.wl][nw.lv]=1;
        nx.fld=nw.fld+1;
        nx.lv=nw.lv-1,nx.wl=nw.wl;
        if(nx.lv>=0 && a[nx.wl][nx.lv]!='X' && !b[nx.wl][nx.lv] && nx.lv>nx.fld)    q.push(nx);
        nx.lv=nw.lv+1,nx.wl=nw.wl;
        if(nx.lv<n && a[nx.wl][nx.lv]!='X' && !b[nx.wl][nx.lv] && nx.lv>nx.fld)     q.push(nx);
        nx.lv=nw.lv+k,nx.wl=1-nw.wl;
        if(nx.lv>=n){
            printf("YES\n");        return 0;
        }
        if(nx.lv<n && a[nx.wl][nx.lv]!='X' && !b[nx.wl][nx.lv] && nx.lv>nx.fld)     q.push(nx);
    }
    printf("NO\n");
    return 0;
}
