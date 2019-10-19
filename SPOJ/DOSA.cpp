#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
multiset<int> s;
multiset<int>::iterator it;
int n,x;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(x<=i)    continue;
        x-=i;
        s.insert(x);
        it=upper_bound(s.begin(),s.end(),x);
        if(it!=s.end())     s.erase(it);
    }
    printf("%d\n",n-s.size());
    return 0;
}
