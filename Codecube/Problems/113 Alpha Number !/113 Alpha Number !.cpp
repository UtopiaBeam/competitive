#include<cstdio>
#include<deque>
#include<algorithm>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int n,b[12];
P a[12];
deque<int> v;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
        a[i]=P(b[i],-i);
    }
    sort(a,a+10);
    if(a[0].F>n){
        printf("-1\n");
        return 0;
    }
    for(int i=0;i<10 && n;i++){
        for(int j=0;j<n/a[i].F;j++)
            v.push_back(-a[i].S);
        n-=a[i].F;
    }
    if(v.size()==1){
        printf("%d\n",v[0]);
        return 0;
    }
    if(v[0]==0){
        v[0]=-a[1].S;
        n-=a[1].F-a[0].F;
        while(n<0 && !v.empty()){
            n+=b[v.front()];
            v.pop_front();
        }
    }
}
