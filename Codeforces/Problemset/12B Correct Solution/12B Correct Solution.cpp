#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[10],b[10];
int main(){
    scanf(" %s %s",a,b);
    int lena=strlen(a);
    sort(a,a+lena);
    if(a[0]=='0')
        for(int i=1;i<lena;i++)
            if(a[i]!='0'){
                a[i]+=a[0],a[0]=a[i]-a[0],a[i]-=a[0];
                break;
            }
    if(!strcmp(a,b))    printf("OK\n");
    else    printf("WRONG_ANSWER\n");
    return 0;
}
