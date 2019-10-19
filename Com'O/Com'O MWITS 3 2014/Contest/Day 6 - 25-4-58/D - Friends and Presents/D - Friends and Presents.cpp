#include<cstdio>
long long cnt1,cnt2,x,y;
bool chk(int n){
    if(n-n/x>=cnt1 && n-n/y>=cnt2)  return true;
    return false;
}
int main(){
    scanf("%I64d %I64d %I64d %I64d",&cnt1,&cnt2,&x,&y);
    long long l=cnt1+cnt2,r=1000000000;
    while(l<r){
        int mid=(l+r)/2;
        if(chk(mid))    r=mid;
        else    l=mid+1;
    }
    printf("%I64d\n",l);
    return 0;
}
