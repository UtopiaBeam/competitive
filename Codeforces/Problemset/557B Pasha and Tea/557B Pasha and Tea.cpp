#include<cstdio>
#include<algorithm>
using namespace std;
int n;
double a[200005],w,mx;
int main(){
    scanf("%d %lf",&n,&w);
    for(int i=0;i<2*n;i++)
        scanf("%lf",&a[i]);
    sort(a,a+2*n);
    if(2*a[0]<=a[n])  mx=a[0]*3.0*n;
    else    mx=a[n]*1.5*n;
    printf("%lf\n",min(mx,w));
    return 0;
}
