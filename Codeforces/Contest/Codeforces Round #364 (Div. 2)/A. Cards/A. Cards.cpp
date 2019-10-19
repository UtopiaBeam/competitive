#include<cstdio>
#include<algorithm>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int n;
P a[102];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].F);
        a[i].S=i+1;
    }
    sort(a,a+n);
    for(int i=0;i<n/2;i++)
        printf("%d %d\n",a[i].S,a[n-i-1].S);
    return 0;
}
