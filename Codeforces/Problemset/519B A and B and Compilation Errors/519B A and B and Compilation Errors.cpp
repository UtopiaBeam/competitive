#include<cstdio>
#include<set>
using namespace std;
multiset <int> a[5];
int n,tmp;
int main(){
    scanf("%d",&n);
    for(int j=0;j<3;j++)
        for(int i=0;i<n-j;i++){
            scanf("%d",&tmp);
            a[j].insert(tmp);
        }
    for(int i=1;i<3;i++)
        for(set <int>::iterator it=a[i].begin();it!=a[i].end();it++)
            a[i-1].erase(a[i-1].find(*it));
    for(int i=0;i<2;i++){
        for(set <int>::iterator it=a[i].begin();it!=a[i].end();it++)
            printf("%d ",*it);
        printf("\n");
    }
    return 0;
}
