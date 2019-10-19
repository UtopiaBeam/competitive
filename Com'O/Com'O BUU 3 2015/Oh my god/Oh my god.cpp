#include<cstdio>
#define MOD 456976
char a[1000002],b[1000002];
int main(){
    scanf(" %s %s",a,b);
    int ha=0,hb=0,i,chk=0,lb=0;
    for(i=0;b[i+1];i++,lb++){
        ha=26*ha+(a[i]-'0');    ha%=MOD;
        hb=26*hb+(b[i]-'0');    hb%=MOD;
    }
    hb=26*hb+(b[i]-'0');    hb%=MOD;
    for(;a[i] && !chk;i++){
        ha=26*ha+(a[i]-'0');    ha%=MOD;
        if(ha==hb){
            int t=1;
            for(int j=0;b[j] && t;j++)
                if(b[j]!=a[i-lb+j])    t=0;
            if(t)       chk=1;
        }
    }
    if(chk)     printf("Lucky\n");
    else        printf("Unlucky\n");
    return 0;
}
