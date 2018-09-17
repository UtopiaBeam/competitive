#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<double,double> worm;
double Max=0.0,sum=0.0,ans1,ans2;
worm a[100005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lf %lf",&a[i].second,&a[i].first);
    sort(a,a+n);
    for(int i=0;i<n;i++){
        sum+=a[i].second;
        if(Max<sum/a[i].first)
            Max=sum/a[i].first,ans1=sum,ans2=a[i].first;
    }
    printf("%.0lf %.0lf\n",ans1,ans2);
    return 0;
}
