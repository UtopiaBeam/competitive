#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005],b[100005],n,len=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        int l=1,r=len;
        while(l<=r){
            int mid=(l+r)/2;
            if(a[b[mid]]<a[i])  l=mid+1;
            else    r=mid-1;
        }
        b[l]=i;
        len=max(len,l);
    }
    printf("%d\n",len);
    return 0;
}
