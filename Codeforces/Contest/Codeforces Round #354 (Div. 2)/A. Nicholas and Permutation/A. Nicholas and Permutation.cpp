#include<cstdio>
#include<algorithm>
using namespace std;
int n,s,e,t;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        if(t==1)    s=i;
        if(t==n)    e=i;
    }
    printf("%d\n",max(max(s-1,n-s),max(e-1,n-e)));
    return 0;
}
