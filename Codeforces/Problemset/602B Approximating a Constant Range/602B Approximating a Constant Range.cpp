#include<cstdio>
#include<deque>
#include<algorithm>
using namespace std;
deque<int> mx,mn;
int n,a[100002],l=0,r=-1,ans=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    while(l<n && ++r<n){
        while(!mn.empty() && a[mn.back()]>a[r])
            mn.pop_back();
        while(!mx.empty() && a[mx.back()]<a[r])
            mx.pop_back();
        mn.push_back(r);    mx.push_back(r);
        while(l<=r && a[mx.front()]-a[mn.front()]>1){
            while(!mx.empty() && mx.front()<=l)
                mx.pop_front();
            while(!mn.empty() && mn.front()<=l)
                mn.pop_front();
            l++;
        }
        ans=max(ans,r-l+1);
    }
    printf("%d\n",ans);
    return 0;
}
