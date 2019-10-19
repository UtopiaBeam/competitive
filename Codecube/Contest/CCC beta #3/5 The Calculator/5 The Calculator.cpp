#include<cstdio>
#include<cstring>
char a[15];
long long b[5],c[5];
int main(){
    for(int i=0;i<3;i++){
        scanf(" %s",a);
        int m=0,len=strlen(a);
        for(int j=0;a[j]!='.' && a[j];j++,m++)
            b[i]*=10,b[i]+=a[j]-'0';
        for(int j=1;j<=10;j++){
            c[i]*=10;
            if(m+j<len)   c[i]+=a[m+j]-'0';
        }
    }
    if((c[0]+c[1])%10000000000==c[2] && b[0]+b[1]+(c[0]+c[1])/10000000000==b[2])    printf("Correct\n");
    else    printf("Wrong\n");
    return 0;
}
