#include<cstdio>
long long a[100005],h,hnow;
int main(){
    int n,q,w;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    hnow=a[0];
    scanf("%d",&q);
    while(q--){
        scanf("%d %I64d",&w,&h);
        if(a[w-1]>hnow){
            hnow=a[w-1];    printf("%I64d\n",hnow);
            hnow+=h;
        }
        else{
            printf("%I64d\n",hnow);   hnow+=h;
        }
    }
    return 0;
}
