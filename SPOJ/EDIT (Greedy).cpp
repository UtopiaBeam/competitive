#include<cstdio>
char a[1002];
int main(){
    while(scanf(" %s",a)!=EOF){
        int cnt1=0,cnt2=0,chk=0;
        for(int i=0;a[i];i++){
            cnt1+=chk*(a[i]>='A' && a[i]<='Z')+(1-chk)*(a[i]>='a' && a[i]<='z');
            chk=1-chk;
        }
        chk=1;
        for(int i=0;a[i];i++){
            cnt2+=chk*(a[i]>='A' && a[i]<='Z')+(1-chk)*(a[i]>='a' && a[i]<='z');
            chk=1-chk;
        }
        if(cnt1<cnt2)   printf("%d\n",cnt1);
        else    printf("%d\n",cnt2);
    }
    return 0;
}
