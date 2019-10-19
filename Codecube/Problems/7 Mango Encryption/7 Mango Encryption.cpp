#include<cstdio>
int trg=1,ans[1000005];
char a[1000005],b[1000005];
int chk(char a,char b){
    if(a>='a' && a<='z')        a-='a';
    else if(a>='A' && a<='Z')   a-='A';
    if(b>='a' && b<='z')        b-='a';
    else if(b>='A' && b<='Z')   b-='A';
    int x=a-b;
    if(x<0)     x+=26;
    if(x>9)     trg=0;
    return x;
}
int main(){
    scanf(" %s %s",a,b);
    for(int i=0;a[i];i++)
        ans[i]=chk(a[i],b[i]);
    if(trg){
        for(int i=0;a[i];i++)
            printf("%d",ans[i]);
        printf("\n");
    }
    else    printf("R.I.P.\n");
    return 0;
}
