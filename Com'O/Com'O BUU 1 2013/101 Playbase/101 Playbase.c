#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    int base,i,lena,lenb,numa=0,numb=0,sum,cnt=0,rmd;
    char a[100],b[100],ans[100];
    scanf("%d %s %s",&base,a,b);
    lena=strlen(a); lenb=strlen(b);
    for(i=0;i<lena;i++){
        numa*=base;
        if(isdigit(a[i]))   numa+=a[i]-'0';
        else                numa+=a[i]-'A'+10;
    }
    for(i=0;i<lenb;i++){
        numb*=base;
        if(isdigit(b[i]))   numb+=b[i]-'0';
        else                numb+=b[i]-'A'+10;
    }
    sum=numa+numb;
    printf("%d\n",sum);
    while(sum){
        rmd=sum%base;
        if(rmd>=10)     ans[cnt]=rmd-10+'A';
        else            ans[cnt]=rmd+'0';
        sum/=base;  cnt++;
    }
    while(--cnt>=0) printf("%c",ans[cnt]);
    printf("\n");
    return 0;
}
