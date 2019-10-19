//Binary Search
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100010];
int main(){
    int n,q,i,p,cnt;
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(&a[0],&a[n-1]);
    while(q--){
        cnt=0;
        scanf("%d",&p);
        for(i=0;i<n;i++){
            if(p<a[i])  break;
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
