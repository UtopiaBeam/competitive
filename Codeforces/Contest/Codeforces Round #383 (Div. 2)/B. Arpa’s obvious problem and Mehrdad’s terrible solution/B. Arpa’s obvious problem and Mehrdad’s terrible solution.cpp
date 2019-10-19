#include<cstdio>
int a[100002],b[100002],n,x;
long long cnt=0;
int main(){
    scanf("%d %d",&n,&x);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        b[a[i]]++;
    }
    for(int i=0;i<n;i++){
        if((a[i]^x)>100000)      continue;
        b[a[i]]--;
        cnt+=b[a[i]^x];
        b[a[i]]++;
    }
    printf("%I64d\n",cnt/2);
    return 0;
}
