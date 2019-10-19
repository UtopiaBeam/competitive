#include<cstdio>
#include<algorithm>
using namespace std;
class pnt{
public:
    int s,e,w;
}a[1000005];
int root[1000005],rank[1000005],n,m;
bool cmp(pnt p,pnt q){
    return p.w<q.w;
}
int find(int i){
    if(root[i]!=i)  root[i]=find(root[i]);
    return root[i];
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d %d %d",&a[i].s,&a[i].e,&a[i].w);
    sort(a,a+m,cmp);
    for(int i=1;i<=n;i++)   root[i]=i;
    for(int i=0;i<m;i++){
        int roots=find(a[i].s),roote=find(a[i].e);
        if(roots==roote)    continue;
        if(rank[roots]<rank[roote]) root[roots]=roote;
        else if(rank[roots]>rank[roote])    root[roote]=roots;
        else    root[roote]=roots,rank[roots]++;
        printf("%d %d\n",a[i].s,a[i].e);
    }
    return 0;
}
