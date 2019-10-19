#include<cstdio>
#include<algorithm>
#include<vector>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
vector<P> ans;
P a[100002];
int t,n;
bool cmp(P x,P y){
    if(x.F!=y.F)    return x.F>y.F;
    return x.S<y.S;
}
int main(){
    scanf("%d",&t);
    while(t--){
        ans.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d %d",&a[i].F,&a[i].S);
        sort(a,a+n,cmp);
//        printf("------\n");
//        for(int i=0;i<n;i++)
//            printf("%d %d\n",a[i].F,a[i].S);
        int mn=a[0].F,mx=a[0].S;
        for(int i=0;i<n;i++)
            if((mn>a[i].F && mx<a[i].S) || (mn==a[i].F && mx==a[i].S))
                mn=a[i].F,mx=a[i].S,ans.push_back(a[i]);
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)
            printf("%d %d\n",ans[i].F,ans[i].S);
    }
    return 0;
}
