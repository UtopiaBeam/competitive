#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000010],n,k;
bool cmp(int i,int j){
    return (i>j);
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    nth_element(a+1,a+k,a+n+1,cmp);
    printf("%d\n",a[k]);
    return 0;
}
