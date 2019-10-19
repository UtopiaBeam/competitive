#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n,m,x[2002],y[2002],d[1002],cnt=1,mx=1;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d %d",&x[i],&y[i]);
    for(int i=0;i<m;i++){
        scanf("%d %d",&x[n+i],&y[n+i]);
        d[i]=(int)1e9;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            d[j]=min(d[j],abs(x[i]-x[n+j])+abs(y[i]-y[n+j]));
    sort(d,d+m);
    for(int i=1;i<m;i++){
        if(d[i]!=d[i-1])    cnt=1;
        else    cnt++;
        mx=max(cnt,mx);
    }
    printf("%d\n",mx);
    return 0;
}
