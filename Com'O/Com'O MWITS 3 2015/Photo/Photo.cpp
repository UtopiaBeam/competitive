#include<cstdio>
#include<algorithm>
#include<map>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int n,s=0,e=-1,cnt=0,mn=1<<30,l=0,b[200002];
map<int,int> m;
P a[200002];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a[i].F,&a[i].S);
        if(m[a[i].S]==0)    m[a[i].S]=++l;
    }
    sort(a,a+n);
    while(s<n && e<n){
        while(cnt<l && e<n){
            e++;
            if(!b[m[a[e].S]])   cnt++;
            b[m[a[e].S]]++;
        }
        if(e>=n)    break;
        mn=min(mn,a[e].F-a[s].F);
        b[m[a[s].S]]--;
        if(!b[m[a[s].S]])   cnt--;
        s++;
    }
    printf("%d\n",mn);
    return 0;
}
