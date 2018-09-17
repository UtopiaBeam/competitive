#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct S{
    double s,q,r;
    bool operator<(const S &x)const{
        return r < x.r;
    }
};
priority_queue<int> hp;
int n,mx=0;
double w,sum=0;
S a[500002];
int main(){
    scanf("%d %lf",&n,&w);
    for(int i=0;i<n;i++){
        scanf("%lf %lf",&a[i].s,&a[i].q);
        a[i].r=a[i].s/a[i].q;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        hp.push(a[i].q);
        sum+=a[i].q;
        while(sum*a[i].r>w){
            sum-=hp.top();
            hp.pop();
        }
        mx=max(mx,(int)hp.size());
    }
    printf("%d\n",mx);
    return 0;
}
