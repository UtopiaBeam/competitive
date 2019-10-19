#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,t,s,e,a[105],b[105];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    while(m--)
        scanf("%d %d",&s,&e);
    sort(b,b+n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i]==b[j]){
                printf("%d ",j%2);
                break;
            }
    return 0;
}
