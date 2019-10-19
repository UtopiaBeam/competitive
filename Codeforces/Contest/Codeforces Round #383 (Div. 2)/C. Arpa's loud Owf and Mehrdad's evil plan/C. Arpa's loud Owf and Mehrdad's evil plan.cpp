#include<cstdio>
#define L long long
int n,a[102],chk[102];
L lcm=-1,cnt=0;
L gcd(L x,L y){
    if(y==0)    return x;
    if(x%y)     return gcd(y,x%y);
    return y;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        if(chk[a[i]]){
            printf("-1\n");
            return 0;
        }
        chk[a[i]]=1;
    }
    for(int i=1;i<=n;i++){
        int nw=i;
        cnt=0;
        do{
            cnt++;
            nw=a[nw];
        }while(nw!=i);
        if(cnt%2==0)    cnt/=2;
        if(lcm<0)       lcm=cnt;
        else            lcm=(cnt*lcm)/gcd(cnt,lcm);
    }
    printf("%I64d\n",lcm);
    return 0;
}
