#include<cstdio>
#include<vector>
using namespace std;
vector<int> a[10002];
int n,s,e;
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&s,&e);
        a[s].push_back(e);
        a[e].push_back(s);
    }
    int p=0,u,v,cnt=n/2+1;
    for(int i=1;i<=n;i++)
        if(a[i].size()==1){
            u=i;    break;
        }
    while(cnt--){
        for(int i=0;i<a[u].size();i++)
            if(p!=a[u][i])
                v=a[u][i];
        p=u;
        u=v;
    }
    printf("%d\n",p);
    return 0;
}
