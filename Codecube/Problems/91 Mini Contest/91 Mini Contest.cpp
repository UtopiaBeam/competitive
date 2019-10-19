#include<cstdio>
int n;
char a[100002];
int main(){
    scanf("%d %s",&n,a);
    for(int i=1;i<n;i++){
        if(a[i]=='X'){
            if(a[i-1]=='B'){
                if(a[i+1]=='W')     a[i]='G';
                else    a[i]='W';
            }
            else if(a[i-1]=='W'){
                if(a[i+1]=='B')    a[i]='G';
                else    a[i]='B';
            }
        }
    }
    for(int i=n-1;i>=0;i--)
        if(a[i]=='X'){
            if(a[i+1]=='B')     a[i]='W';
            else    a[i]='B';
        }
    printf("%s\n",a);
    return 0;
}
