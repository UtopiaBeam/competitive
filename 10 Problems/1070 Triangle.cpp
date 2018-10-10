#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100010];
int main(){
    int n,i,chk=1;
    scanf("%d",&n);
    if(n<3)    { printf("no\n");    return 0; }
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    if(a[0]+a[1]<=a[n-1])     printf("yes\n");
    else                      printf("no\n");
    return 0;
}
