#include<cstdio>
#include<algorithm>
using namespace std;
pair<long long,long long> a[100005];
int n;
long long sum=0,cnt=0,r,k;
bool cmp(pair<long long,long long> p,pair<long long,long long> q){
    return p.second < q.second;
}
int main(){
    scanf("%d %I64d %I64d",&n,&r,&k);
    k*=n;
    for(int i=0;i<n;i++){
        scanf("%I64d %I64d",&a[i].first,&a[i].second);
        sum+=a[i].first;
    }
    k-=sum;
    sort(a,a+n,cmp);
    for(int i=0;i<n && k>0;i++){
        if(r-a[i].first<=k)   k-=r-a[i].first,cnt+=a[i].second*(r-a[i].first);
        else    cnt+=k*a[i].second,k=0;
    }
    printf("%I64d\n",cnt);
    return 0;
}
