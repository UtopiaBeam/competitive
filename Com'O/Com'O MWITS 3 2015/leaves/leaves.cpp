#include<cstdio>
#include<vector>
using namespace std;
int n,pre[100002],post[100002],t,nw=1;
vector<int> v;
void f(int s,int e){
    if(s>e || nw>n)     return ;
    int u=pre[nw++],m=post[u];
    if(s==m)    v.push_back(u);
    f(s,m-1);   f(m+1,e);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&pre[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        post[t]=i;
    }
    f(1,n);
    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++)
        printf("%d ",v[i]);
    return 0;
}
