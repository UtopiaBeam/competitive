#include<cstdio>
#include<algorithm>
using namespace std;
int m,s,c,a[202];
int main(){
    scanf("%d %d %d",&m,&s,&c);
    for(int i=0;i<c;i++)    scanf("%d",&a[i]);
    sort(a,a+c);
    s=a[c-1]-a[0]+1;
    for(int i=c-1;i>0;i--)    a[i]=a[i-1]-a[i]+1;
    sort(a,a+c);
    for(int i=0;i<m-1 && i<c-1;i++)    s+=a[i];
    printf("%d\n",s);
    return 0;
}
