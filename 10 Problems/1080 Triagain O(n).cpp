#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[30002],s,mx=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    if(n<3){
        printf("%d\n",n);
        return 0;
    }
    sort(a,a+n);
    for(int i=0;s<n && n-i>mx;i++){
        int t=a[i]+a[i+1];
        while(s<n && a[s]<t)   s++;
        mx=max(mx,s-i);
    }
    printf("%d\n",mx);
    return 0;
}
