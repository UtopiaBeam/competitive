#include<cstdio>
#include<cstring>
int q,len;
char a[10002];
int main(){
    scanf("%d",&q);
    while(q--){
        int chp=1;
        scanf(" %s",a);
        len=strlen(a);
        for(int i=1;i<=len && chp;i++)
            if(len%i==0){
                int chk=1;
                for(int j=0;j<len && chk;j+=i)
                    if(strncmp(a,a+j,i))    chk=0;
                if(chk)     printf("%d\n",len/i),chp=0;
            }
    }
    return 0;
}
