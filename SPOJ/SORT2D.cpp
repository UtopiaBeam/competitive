#include<cstdio>
#include<algorithm>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int n,q;
P a[100002];
int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d %d",&a[i].F,&a[i].S);
            a[i].S*=-1;
        }
        sort(a,a+n);
        for(int i=0;i<n;i++)
            printf("%d %d\n",a[i].F,-a[i].S);
    }
    return 0;
}
