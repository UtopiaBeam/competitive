#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100005],cnt=1,t=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=n-2;i>=0;i--)
        if(a[i]==a[i+1]){
            t++;
            if(t>=cnt)  cnt++;
        }
        else    t=0;
    printf("%d\n",cnt);
}
