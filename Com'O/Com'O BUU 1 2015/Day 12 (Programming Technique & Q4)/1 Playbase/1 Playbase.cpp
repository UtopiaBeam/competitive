#include<cstdio>
#include<cstring>
#include<cctype>
int n,na=0,nb=0,cnt=0;
char a[15],b[15],c[15];
int main(){
    scanf("%d %s %s",&n,a,b);
    for(int i=0;a[i];i++){
        na*=n;
        if(isdigit(a[i]))   a[i]-='0';
        else    a[i]-='A'-10;
        na+=a[i];
    }
    for(int i=0;b[i];i++){
        nb*=n;
        if(isdigit(b[i]))   b[i]-='0';
        else    b[i]-='A'-10;
        nb+=b[i];
    }
    na+=nb;
    printf("%d\n",na);
    while(na){
        int t=na%n;
        if(t<10)   c[cnt++]=t+'0';
        else    c[cnt++]=t-10+'A';
        na/=n;
    }
    while(--cnt+1)    printf("%c",c[cnt]);
    return 0;
}
