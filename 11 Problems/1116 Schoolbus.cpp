#include<cstdio>
#include<algorithm>
using namespace std;
double a[1000005],m=0,ans=0;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lf",&a[i]);
    for(int i=1;i<n;i++){
        m=max(m,a[i-1]);
        if(m>a[i])     ans=max(ans,(m-a[i])/2);
    }
    printf("%lf\n",ans);
    return 0;
}
