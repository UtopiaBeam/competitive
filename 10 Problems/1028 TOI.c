#include<stdio.h>
#include<string.h>
#include<math.h>
double a[30];
char b[15];
int main(){
    int len,i;
    while(1){
        gets(b);
        if(b[0]=='!'){
            printf("!\n");
            return 0;
        }
        if(b[0]=='+')
            a[b[2]-'A']+=a[b[4]-'A'];
        if(b[0]=='-')
            a[b[2]-'A']-=a[b[4]-'A'];
        if(b[0]=='*')
            a[b[2]-'A']*=a[b[4]-'A'];
        if(b[0]=='/')
            a[b[2]-'A']/=a[b[4]-'A'];
        if(b[0]=='='){
            len=strlen(b);  a[b[2]-'A']=0;
            if(b[4]=='-')
                for(i=5;i<len;i++)
                    a[b[2]-'A']-=pow(10,len-i-1)*(b[i]-'0');
            else for(i=4;i<len;i++)
                a[b[2]-'A']+=pow(10,len-i-1)*(b[i]-'0');
        }
        if(b[0]=='#')
            printf("%.0lf\n",floor(a[b[2]-'A']));
    }
    return 0;
}
