#include<cstdio>
#include<algorithm>
using namespace std;
int n,h,l,r,nw=0;
int main(){
    scanf("%d",&n);
    for(h=1;(h*(h+1))/2<n;h++);
    if(h%2)     l=h-1,r=max(n-(h*(h-1))/2,h-2);
    else        r=h-1,l=max(n-(h*(h-1))/2,h-2);
    for(int i=1;i<=h;i++){
        int len=min(i,n-(i*(i-1))/2);
        if(i%2){
            for(int j=1;j<l;j++)    printf(".");
            for(int j=0;j<len;j++)  printf("%c",nw+'A'),nw=(nw+27)%26;
            for(int j=0;j<r-len;j++)    printf(".");
        }
        else{
            nw+=len-1,nw%=26;
            for(int j=0;j<l-len;j++)    printf(".");
            for(int j=0;j<len;j++)  printf("%c",nw+'A'),nw=(nw+25)%26;
            for(int j=1;j<r;j++)    printf(".");
            nw+=len+1,nw%=26;
        }
        printf("\n");
    }
    return 0;
}
