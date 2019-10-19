#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int a[10010],i,Max=0,n,cnt[10010],lim=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        lim=max(lim,a[i]);
    }
    sort(a,a+n);
    for(i=0;i<n;i++){
        cnt[a[i]]++;
        Max=max(Max,cnt[a[i]]);
    }
    for(i=1;i<=lim;i++)
        if(cnt[i]==Max)
            printf("%d ",i);
    printf("\n");
    return 0;
}
