#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100002],b[100002],l[100002],r[100002],len=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        int s=1,e=len;
        while(s<=e){
            int m=(s+e)/2;
            if(a[b[m]]<a[i])   s=m+1;
            else    e=m-1;
        }
        b[s]=i,l[i]=s;
        len=max(len,s);
    }
    len=0;
    memset(b,0,sizeof(b));
    for(int i=n-1;i>=0;i--){
        int s=1,e=len;
        while(s<=e){
            int m=(s+e)/2;
            if(a[b[m]]<a[i])    s=m+1;
            else    e=m-1;
        }
        b[s]=i,r[i]=s;
        len=max(len,s);
    }
    len=0;
    for(int i=0;i<n;i++)
        len=max(len,l[i]+r[i]-1);
    printf("%d\n",len);
    return 0;
}
