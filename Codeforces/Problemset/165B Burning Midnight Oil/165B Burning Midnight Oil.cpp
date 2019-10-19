#include<cstdio>
#define L long long
L n,k;
bool chk(L x){
    L t=0;
    while(x){
        t+=x;
        x/=k;
    }
    return t>=n;
}
L bs(L s,L e){
    if(s>=e)    return s;
    L m=(s+e)/2;
    if(chk(m))      return bs(s,m);
    return bs(m+1,e);
}
int main(){
    scanf("%I64d %I64d",&n,&k);
    printf("%I64d\n",bs(1,1e9));
    return 0;
}
