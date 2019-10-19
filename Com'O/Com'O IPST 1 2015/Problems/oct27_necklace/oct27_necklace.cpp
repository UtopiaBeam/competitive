#include<cstdio>
#include<list>
using namespace std;
list<int> l[300002];
list<int>::iterator it;
list<int>::reverse_iterator r_it;
int r[300002];
int n,x,y;
int f(int x){
    if(x!=r[x])     r[x]=f(r[x]);
    return r[x];
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)   l[i].push_back(i),r[i]=i;
    for(int i=1;i<n;i++){
        scanf("%d %d",&x,&y);
        int rx=f(y);
        for(it=l[rx].begin();it!=l[rx].end();it++){
            if(*it==y){
                l[y].insert(it,l[x].begin(),l[x].end());
                l[x].clear(),r[x]=y;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(!l[i].empty()){
            for(r_it=l[i].rbegin();r_it!=l[i].rend();r_it++)
                printf("%d ",*r_it);
            break;
        }
    return 0;
}
