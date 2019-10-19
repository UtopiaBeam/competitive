#include<cstdio>
#include<cctype>
char a[100002];
int MOD=(int)(1e9+7),ans=1;
int cnt(int x){
    int t=0;
    for(int i=0;i<6;i++){
        t+=3-3*(x%2);
        x/=2;
    }
    return t;
}
int main(){
    scanf(" %s",a);
    for(int i=0;a[i];i++){
        int t;
        if(isdigit(a[i]))   t=a[i]-'0';
        else if(isupper(a[i]))
            t=a[i]-'A'+10;
        else if(islower(a[i]))
            t=a[i]-'a'+36;
        else if(a[i]=='-')  t=62;
        else        t=63;
        ans*=cnt(t);    ans%=MOD;
    }
    printf("%d\n",ans);
    return 0;
}
