#include<cstdio>
#include<queue>
#include<map>
using namespace std;
queue<int> a,b;
map<queue<int>,int> chk;
int n,k,t,cnt=0;
int main(){
    scanf("%d %d",&n,&k);
    while(k--){
        scanf("%d",&t);
        a.push(t);
    }
    scanf("%d",&k);
    while(k--){
        scanf("%d",&t);
        b.push(t);
    }
    while(a.size() && b.size()){
        if(chk[a] && chk[b]){
            printf("-1\n");
            return 0;
        }
        chk[a]=chk[b]=1,cnt++;
        if(a.front()>b.front())
            a.push(b.front()),a.push(a.front());
        else    b.push(a.front()),b.push(b.front());
        a.pop(),b.pop();
    }
    printf("%d ",cnt);
    if(a.size())    printf("1\n");
    else    printf("2\n");
    return 0;
}
