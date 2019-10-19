#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[10002],b[5002];
int la,lb,ca=1,cb=1;
int main(){
    scanf(" %s %s",a,b);
    la=strlen(a),lb=strlen(b);
    if(a[0]=='-')   strcpy(a,a+1),la--,ca=-1;
    if(b[0]=='-')   strcpy(b,b+1),lb--,cb=-1;
    for(int i=0;i<la/2;i++)     swap(a[i],a[la-1-i]);
    for(int i=0;i<la;i++)   a[i]-='0';
    for(int i=0;i<lb;i++){
        b[i]-='0';
        for(int j=0;j<la;j++)   a[j]*=b[i];
        for(int j=0;j<la;j++){
            if(a[j]>10){
                if(j==la-1) la++;
                a[j+1]+=a[j]/10,a[j]%=10;
            }
        }
    }
    if(ca*cb<0)     printf("-");
    for(int i=la-1;i>=0;i--)    printf("%d",a[i]);
    return 0;
}
