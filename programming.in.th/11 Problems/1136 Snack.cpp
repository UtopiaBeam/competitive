#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
double a[1000005],b[1000005],suma=0,sumb=0;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lf",&a[i]);
        suma+=a[i]/n;
    }
    for(int i=0;i<m;i++){
        scanf("%lf",&b[i]);
        sumb+=b[i]/m;
    }
    return 0;
}
