#include<cstdio>
#include<algorithm>
using namespace std;
int q,n,a[202];
int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)    scanf("%d",&a[i]);
        int cnt=0;
        sort(a,a+n);
        while(a[0]){
            for(int i=1;i<n;i++)    a[i]--;
            sort(a,a+n);    cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
