#include<cstdio>
#include<algorithm>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int n,mx1=0,mx2=0,s=0,e=0;
P a[50002];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&a[i].F,&a[i].S);
    sort(a,a+n);
    s=a[0].F,e=a[0].S;
    mx1=e-s;
    for(int i=1;i<n;i++){
        if(a[i].F>e){
            mx2=max(mx2,a[i].F-e);
            s=a[i].F;
        }
        e=max(e,a[i].S);
        mx1=max(mx1,e-s);
    }
    printf("%d %d\n",mx1,mx2);
    return 0;
}
