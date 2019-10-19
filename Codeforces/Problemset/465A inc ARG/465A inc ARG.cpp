#include<cstdio>
char a[105];
int n;
int main(){
    scanf("%d %s",&n,a);
    a[0]++;
    for(int i=0;i<n;i++)
        if(a[i]>'1' && i<n-1)
            a[i]='0',a[i+1]++;
        else{
            printf("%d\n",i+1);       return 0;
        }
    return 0;
}
