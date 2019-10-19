#include<cstdio>
#include<cstring>
#include<cctype>
char a[1002],b[1002];
int cnt=0;
int main(){
    gets(a);
    for(int i=0;a[i];i++)
        b[i]=tolower(a[i]);
    for(int i=0;a[i];i++)
        if(strncmp("sipa",b+i,4))
            printf("%c",a[i]);
        else    printf("\"%c%c%c%c\"",a[i],a[i+1],a[i+2],a[i+3]),i+=3,cnt++;
    printf("\n%d\n",cnt);
    return 0;
}
