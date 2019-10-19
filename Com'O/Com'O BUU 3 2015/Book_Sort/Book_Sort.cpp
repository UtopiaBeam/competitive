#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
struct S{
    char s[22];
    int in;
}a[300002];
int n,b[300002];
bool cmp(S x,S y){
    if(strcmp(x.s,y.s))
        return strcmp(x.s,y.s)<0;
    return x.in<y.in;
}
int main(){
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %s",a[i].s);
        for(int j=0;a[i].s[j];j++)
            if(a[i].s[j]>='A' && a[i].s[j]<='Z')
                a[i].s[j]-='A'-'a';
        // printf("%s\n",a[i].s);
        a[i].in=i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        printf("%s\n",a[i].s);
        b[a[i].in]=min(i,a[i].in);
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",b[i]);
    return 0;
}
