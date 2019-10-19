#include<cstdio>
#include<algorithm>
using namespace std;
char a[1005];
int n,p;
int main(){
    scanf("%d %d %s",&n,&p,a);
    while(1){
        int now=n-1;
        a[now]++;
        while(now>=0 && a[now]>'a'+p-1)
            a[now--]='a',a[now]++;

        for(int i=2;i<n;i++){
            if(a[i-2]==a[i]||a[i-1]==a[i]||a[i-1]==a[i-2])  break;
            if(i==n-1){
                printf("%s\n",a);   return 0;
            }
        }
    }
}
