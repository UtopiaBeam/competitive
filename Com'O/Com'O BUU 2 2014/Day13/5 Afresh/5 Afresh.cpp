#include<cstdio>
#include<algorithm>
using namespace std;
int n,c,a[1010],b[1010],cnt[1010];
int main(){
    int i,j=0;
    scanf("%d %d",&n,&c);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b,b+n);
    for(i=0;i<n;i++){
        if(b[i]==b[i+1])
            cnt[j]++;
        else    cnt[j++];
    }
    for(i=0;i<j;i++)
        printf("%d ",cnt[i]);
    printf("\n");
}
