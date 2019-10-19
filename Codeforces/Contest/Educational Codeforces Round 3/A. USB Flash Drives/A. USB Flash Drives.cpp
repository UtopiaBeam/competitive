#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[102];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        m-=a[i];
        if(m<=0){
            printf("%d\n",n-i);
            return 0;
        }
    }
}
