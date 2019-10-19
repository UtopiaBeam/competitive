#include<cstdio>
#include<deque>
#define dif a[mx.front()]-a[mn.front()]
using namespace std;
int n,x,y,l=0,r=-1,a[1000002];
long long cnt=0;
deque<int> mn,mx;
int main(){
    scanf("%d %d %d",&n,&x,&y);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    while(l<n && ++r<n){
        while(!mn.empty() && a[mn.back()]>a[r])
            mn.pop_back();
        while(!mx.empty() && a[mx.back()]<a[r])
            mx.pop_back();
        mn.push_back(r);    mx.push_back(r);
    }
    return 0;
}
