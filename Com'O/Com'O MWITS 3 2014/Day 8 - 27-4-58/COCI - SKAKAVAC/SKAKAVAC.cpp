#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[1005][1005],mark[1005][1005],ans=0,n,r,c;
void f(int i,int j,int cnt){
    if(mark[i][j]>cnt)      return ;
    mark[i][j]=cnt,ans=max(ans,cnt);
    for(int k=0;k<n;k++){
        if(abs(k-i)>1){
            ;
        }
    }
}
int main(){
    scanf("%d %d %d",&n,&r,&c);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    f(r,c,1);
}
