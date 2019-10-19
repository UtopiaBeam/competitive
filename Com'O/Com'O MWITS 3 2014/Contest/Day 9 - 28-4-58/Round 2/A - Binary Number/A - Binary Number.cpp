#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char a[100005];
int cnt=0,l,r;
void add(int tmp){
    a[tmp]='0',a[++tmp]++;
    while(a[tmp]>'1'){
        a[tmp++]='0',a[tmp]++;
        if(tmp>r)   r++,a[tmp]='1';
    }
}
int main(){
    scanf(" %s",&a);
    l=0,r=strlen(a)-1;
    for(int i=0;i<=r/2;i++)
        swap(a[i],a[r-i]);
    while(l<r){
        if(a[l]=='1')  add(l),cnt++;
        l++,cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
