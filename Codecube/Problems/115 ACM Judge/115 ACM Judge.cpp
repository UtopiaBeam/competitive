#include<cstdio>
#include<cstring>
int t;
char a[22];
int main(){
    scanf("%d ",&t);
    for(int i=1;i<=t;i++){
        int chk=0;
        scanf(" %s",a);
        int len=strlen(a);
        for(int j=0;j<len;j++){
            if(a[j]=='X')   chk=3;
            if(a[j]=='T' && chk<=2)  chk=2;
            if(a[j]=='-' && chk<=1)  chk=1;
        }
        printf("Case #%d: ",i);
        if(chk==0)      printf("Yes\n");
        else if(chk==1) printf("No - Wrong answer\n");
        else if(chk==2) printf("No - Time limit exceeded\n");
        else    printf("No - Runtime error\n");
    }
    return 0;
}
