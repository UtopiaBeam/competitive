#include<cstdio>
int main(){
    int n,nw=0;
    scanf("%d",&n);
    while(n){
        int t=nw,tmp=0;
        while(t){
            tmp*=10;
            if(t%10==6) tmp+=9;
            else if(t%10==9)    tmp+=6;
            else if(t%10==0 || t%10==1 || t%10==8)  tmp+=t%10;
            else    break;
            t/=10;
        }
        if(tmp==nw) n--;
        nw++;
    }
    printf("%d\n",nw-1);
    return 0;
}
