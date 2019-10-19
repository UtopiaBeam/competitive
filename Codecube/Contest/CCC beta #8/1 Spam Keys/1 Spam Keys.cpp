#include<cstdio>
#include<cstring>
int n,cnt=0;
char a[100002];
int main(){
    scanf("%d %s",&n,a);
    for(int i=0;i<n;i++){
        if(a[i]=='Q' || a[i]=='W' || a[i]=='E' || a[i]=='A' || a[i]=='D' || a[i]=='V')
            cnt++;
        else if(a[i]=='S'){
            cnt++;
            if(!strncmp(a+i,"SHIFT",5))  i+=4;
            else if(!strncmp(a+i,"SPACEBAR",8))  i+=7;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
