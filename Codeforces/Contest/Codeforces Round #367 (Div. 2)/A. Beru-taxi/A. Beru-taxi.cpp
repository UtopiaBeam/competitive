#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
double x,y,mn=1<<30,xt,yt,vt;
int n;
int main(){
    scanf("%lf %lf %d",&x,&y,&n);
    while(n--){
        scanf("%lf %lf %lf",&xt,&yt,&vt);
        mn=min(mn,sqrt((x-xt)*(x-xt)+(y-yt)*(y-yt))/vt);
    }
    printf("%lf\n",mn);
    return 0;
}
