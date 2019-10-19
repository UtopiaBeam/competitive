#include<cstdio>
#include<algorithm>
using namespace std;
#define P pair<int,int>
#define F first
#define S second
int n,b[100002];
P a[100002];
int main(){
    while(scanf("%d",&n) && n){
        int len=0;
        for(int i=0;i<n;i++)
            scanf("%d %d",&a[i].F,&a[i].S);
        sort(a,a+n);
        for(int i=0;i<n;i++){
            int s=1,e=len;
            while(s<=e){
                int m=(s+e)/2;
                if(a[b[m]].S<=a[i].S)    s=m+1;
                else    e=m-1;
            }
            b[s]=i;
            len=max(len,s);
        }
        printf("%d\n",len);
    }
    return 0;
}
