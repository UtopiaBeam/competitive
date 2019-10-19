#include<cstdio>
#include<algorithm>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int n,s=0,e=0,mxb=0,mxc=0;
P a[50002];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)    scanf("%d %d",&a[i].F,&a[i].S);
    sort(a,a+n);
    s=a[0].F,e=a[0].S;
    for(int i=1;i<n;i++){
        if(a[i].F>e){
            mxb=max(mxb,a[i].F-e);
            s=a[i].F;
        }
        e=max(e,a[i].S);
        mxc=max(mxc,e-s);
    }
    printf("%d %d\n",mxc,mxb);
    return 0;
}
