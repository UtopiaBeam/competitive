#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,s[520][520];
char a[520][520];
int sum(int lx,int ly,int rx,int ry){
    return s[rx+1][ry+1]-s[lx][ry+1]-s[rx+1][ly]+s[lx][ly];
}
int f(int lx,int ly,int rx,int ry,int s){
    if(s==1)    return 0;
    int mx=(lx+rx)/2,my=(ly+ry)/2,ans=1<<30;
    int b[4]={sum(lx,ly,mx,my),sum(lx,my+1,mx,ry),sum(mx+1,ly,rx,my),sum(mx+1,my+1,rx,ry)},
        c[4]={f(lx,ly,mx,my,s>>1),f(lx,my+1,mx,ry,s>>1),f(mx+1,ly,rx,my,s>>1),f(mx+1,my+1,rx,ry,s>>1)};
    for(int i=3;i<16;i++){
        int t=i,cnt=0,tmp=0;
        vector<int> d;
        while(t)    cnt+=t%2,t=t>>1;
        if(cnt!=2)  continue;
        t=i,cnt=0;
        for(int j=0;j<4;j++){
            if(t%2)     tmp+=c[cnt];
            else    d.push_back(b[cnt]);
            cnt++,t=t>>1;
        }
        ans=min(ans,tmp+min(d[0],d[1])+((s*s)>>2)-max(d[0],d[1]));
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            scanf(" %c",&a[i][j]);
            s[i+1][j+1]=s[i][j+1]+s[i+1][j]-s[i][j]+a[i][j]-'0';
        }
    printf("%d\n",f(0,0,n-1,n-1,n));
    return 0;
}
