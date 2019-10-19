#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005],b[100005],n1,n2,m1,m2,pa=0,pb=0;
int main(){
    scanf("%d %d %d %d",&n1,&n2,&m1,&m2);
    for(int i=0;i<n1;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n2;i++)
        scanf("%d",&b[i]);
    while(m1 && pb<n2){
        if(a[pa]<b[pb])     pa++,m1--;
        else    pb++;
    }
    if(m1 || n2-pb<m2)    printf("NO\n");
    else    printf("YES\n");
    return 0;
}
