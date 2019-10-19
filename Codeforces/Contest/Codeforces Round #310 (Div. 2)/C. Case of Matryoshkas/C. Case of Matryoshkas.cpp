#include<cstdio>
#include<algorithm>
using namespace std;
pair<int,int> a[100005];
int b[100005],cnt=1,n,k,m;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1,j=1;i<=k;i++){
        scanf("%d",&m);
        while(m--){
            scanf("%d",&a[j].first);
            a[j++].second=i;
        }
        b[i]=-1;
    }
    sort(a+1,a+n+1);
    b[a[0].second]++;
    for(int i=2;i<=n;i++)
        if(a[i].second!=a[i-1].second)    cnt++,b[a[i].second]++;
    for(int i=1;i<=k;i++)
        cnt+=b[i];
    printf("%d\n",cnt);
    return 0;
}
