#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,last=0,len=0;
pair<long long,int> ans[1000005];
char a[1000005];
int main(){
    scanf("%d %d %s",&n,&k,a);
    for(int i=0;a[i];i++){
        ans[i+1].second=i+1;
        if(a[i]=='R')   ans[i+1].first=k+ans[i].first;
        else    ans[i+1].first=ans[i].first-1;
    }
    sort(ans,ans+n+1);
    for(int i=1;i<=n;i++){
        if(ans[i].first==ans[last].first)
            len=max(len,ans[i].second-ans[last].second);
        else    last=i;
    }
    printf("%d\n",len);
    return 0;
}
