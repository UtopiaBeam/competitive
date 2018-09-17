#include<cstdio>
#include<algorithm>
using namespace std;
int a[30010],n,ans,len;
int find(int key,int str,int end){
    if(key<a[str])      return str;
    if(key>a[end])      return end;
    if(str+1==end)      return str;
    int mid=(str+end)/2;
    if(key==a[mid]){
        while(a[mid]==a[mid+1])     mid++;
        return mid;
    }
    if(key<a[mid])      return find(key,str,mid);
    if(key>a[mid])      return find(key,mid,end);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	if(n<3){
        printf("%d\n",n);
        return 0;
	}
	sort(a,a+n);
	for(int i=0;i<n-1;i++){
        if(n-i<len)     break;
        int in=find(a[i]+a[i+1]-1,i,n-1);
        len=max(len,in-i+1);
	}
	printf("%d\n",len);
	return 0;
}
