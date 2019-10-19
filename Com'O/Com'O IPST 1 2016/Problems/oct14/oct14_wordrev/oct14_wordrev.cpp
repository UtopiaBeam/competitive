#include<cstdio>
char a[1002];
int s=0;
void rev(int i){
    if(i<s)     return ;
    printf("%c",a[i]);
    rev(i-1);
}
void wrev(int i){
    if(!a[i]){
        rev(i-1);   return ;
    }
    else if(a[i]=='_'){
        rev(i-1);   s=i+1;
        printf("%c",a[i]);
    }
    wrev(i+1);
}
int main(){
    gets(a);
    wrev(0);
    return 0;
}
