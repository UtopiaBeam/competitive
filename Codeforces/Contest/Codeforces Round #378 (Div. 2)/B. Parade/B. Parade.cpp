#include<cstdio>
#include<algorithm>
using namespace std;
int n,l[100002],r[100002],suml=0,sumr=0,mx=0,idx=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",l+i,r+i);
        suml+=l[i];
        sumr+=r[i];
    }
    mx=abs(suml-sumr);
    for(int i=1;i<=n;i++){
        suml-=l[i]-r[i];
        sumr-=r[i]-l[i];
        if(mx<abs(suml-sumr))
            mx=abs(suml-sumr),idx=i;
        suml+=l[i]-r[i];
        sumr+=r[i]-l[i];
    }
    printf("%d\n",idx);
    return 0;
}
