#include<cstdio>
#include<algorithm>
using namespace std;
int q,n;
pair<int,int> a[10005];
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first!=b.first)    return a.first>b.first;
    return a.second>b.second;
}
int main(){
    scanf("%d",&q);
    while(q--){
        int cnt=1;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d %d",&a[i].first,&a[i].second);
        sort(a,a+n,cmp);
        for(int i=1;i<n;i++)
            if(a[i].first>=a[i-1].first || a[i].second>=a[i-1].second)
                cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
