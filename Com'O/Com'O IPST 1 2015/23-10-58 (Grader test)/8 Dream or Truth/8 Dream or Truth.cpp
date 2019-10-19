#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[602],t[602],b[602],c[602];
int main(){
    scanf(" %s %s %s",a,b,c);
    int la=strlen(a),lb=strlen(b),lc=strlen(c);
    for(int i=0;i<la;i++)   a[i]-='0';
    for(int i=0;i<lb;i++)   b[i]-='0';
    for(int i=0;i<lc;i++)   c[i]-='0';
    for(int i=0;i<la/2;i++)     swap(a[i],a[la-1-i]);
    for(int i=0;i<lc/2;i++)     swap(c[i],c[lc-1-i]);
    for(int i=0;i<la;i++)   t[i]=a[i];
    memset(a,0,sizeof(a));
    for(int i=lb-1,s=0;i>=0;i--,s++,la++){
        for(int j=0;j<la;j++)   a[s+j]+=t[j]*b[i];
        for(int j=0;j<la;j++){
            if(a[j]>9){
                if(j==la-1)     la++;
                a[j+1]+=a[j]/10,a[j]%=10;
            }
        }
    }
    for(int i=0;i<la-2;i++)
        if(a[i]!=c[i]){
            printf("dream\n");      return 0;
        }
    printf("truth\n");
    return 0;
}
