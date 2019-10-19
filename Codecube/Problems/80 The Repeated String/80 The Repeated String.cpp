#include<cstdio>
#include<cstring>
char a[100002];
int len,cnt;
int main(){
    for(int k=0;k<5;k++){
        cnt=0;
        scanf(" %s",a);
        len=strlen(a);
        for(int i=1;i<=len;i++){
            if(len%i==0){
                int chk=1;
                for(int j=0;j<len;j+=i){
                    if(strncmp(a,a+j,i)){
                        chk=0;  break;
                    }
                }
                cnt+=chk;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
