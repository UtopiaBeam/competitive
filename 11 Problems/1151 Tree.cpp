#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[200010],b[200010],len=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        int str=1,end=len;
        while(str<=end){
            int mid=(str+end)/2;
            if(a[b[mid]]<a[i])  str=mid+1;
            else    end=mid-1;
        }
        b[str]=i;
        len=max(str,len);
    }
    printf("%d\n",len);
    return 0;
}
