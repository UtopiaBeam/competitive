#include<cstdio>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;
#define P pair<int,int>
#define F first
#define S second
P a[100002];
int b[100002],n,mn=INT_MAX,mx=INT_MIN,s=0,cnt=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].F);
        a[i].S=i;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
        b[i]=a[i].S;
    for(int i=0;i<n;i++){
        mn=min(mn,b[i]);
        mx=max(mx,b[i]);
        if(mn==s && mx==i){
            cnt++;      s=i+1;
            mn=INT_MAX; mx=INT_MIN;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
