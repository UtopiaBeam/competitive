#include<cstdio>
#include<algorithm>
using namespace std;
int a[10005],n;
bool cmp(int a,int b){  return a>b; }
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){

    }
}
