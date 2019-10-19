#include<cstdio>
char a[102];
int main(){
    scanf(" %s",a);
    for(int i=0;a[i];i++){
        if('A'<=a[i] && a[i]<='Z')  a[i]-='A'-'a';
        if(a[i]!='a' && a[i]!='e' && a[i]!='i' && a[i]!='o' && a[i]!='u' && a[i]!='y')
            printf(".%c",a[i]);
    }
    return 0;
}
