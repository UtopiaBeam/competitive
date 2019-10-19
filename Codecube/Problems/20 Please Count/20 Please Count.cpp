#include<cstdio>
#include<vector>
using namespace std;
vector <int> a;
int q,n,cnt[3500005],tmp;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        cnt[tmp]++;
    }
    for(int i=0;i<=n;i++){
        while(cnt[i]--)
            a.push_back(i);
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&tmp);
        printf("%d\n",a[n-1]-a[tmp-1]);
    }
    return 0;
}
