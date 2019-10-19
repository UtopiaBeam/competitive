#include<cstdio>
#include<algorithm>
#define F first
#define S second
using namespace std;
int s[200005],e[200005],n,m;
pair<int,int> a[200005];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d %d",&s[i],&e[i]);
    for(int i=0;i<m;i++){
        scanf("%d",&a[i].F);
        a[i].S=i;
    }
    sort(a,a+n);
}
