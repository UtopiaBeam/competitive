#include<cstdio>
#include<algorithm>
#define F first
#define S second
using namespace std;
int n,b[100005][2];
pair<int,int> a[100005];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].F);
        a[i].S=i;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        b[a[i].S][0]=min(i>0? a[i].F-a[i-1].F:2e9,i<n-1? a[i+1].F-a[i].F:2e9);
        b[a[i].S][1]=max(a[i].F-a[0].F,a[n-1].F-a[i].F);
    }
    for(int i=0;i<n;i++)
        printf("%d %d\n",b[i][0],b[i][1]);
    return 0;
}
