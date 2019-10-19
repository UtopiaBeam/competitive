#include<cstdio>
#include<set>
using namespace std;
int n,q,m,x;
set<int> a[25];
int main(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&m);
        while(m--){
            scanf("%d",&x);
            a[i].insert(x);
        }
    }
    while(q--){
        scanf("%d %d",&m,&x);
        if(m){
            int mn=0,mnt=1<<20;
            for(int i=1;i<=n;i++){
                int t=distance(a[i].begin(),a[i].upper_bound(x));
                if(mnt>t)   mn=i,mnt=t;
            }
            a[mn].insert(x);
            printf("%d\n",mn);
        }
        else if(!a[x].empty())   a[x].erase(a[x].begin());
    }
    return 0;
}
