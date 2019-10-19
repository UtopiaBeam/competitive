#include<cstdio>
int n,a[100002],l=1,r=0,sum=0,nw=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        sum+=a[i];
    }
    while(l<=n && ++r<=n){
        nw+=a[r];
        while(2*nw>sum && l<=r)   nw-=a[l++];
        if(2*nw==sum){
            if(l>1)   printf("%d ",l-1);
            printf("%d\n",r);
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
