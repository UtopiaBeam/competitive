#include<cstdio>
#include<stack>
using namespace std;
class C{
public:
    int s,f;
}t;
stack<C> s;
int n;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&t.s,&t.f);
        while(!s.empty() && s.top().s<t.s){
            printf("%d\n",s.top().f);   s.pop();
        }
        s.push(t);
    }
    return 0;
}
