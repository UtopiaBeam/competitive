#include<cstdio>
char a[1002],b[1002];
int s=0,in=0;
void print_rev(int i){
    if(i<s)     return ;
    printf("%c",a[i]);
    print_rev(i-1);
}
void rev(int i){
    if(!b[i])    return ;
    rev(i+1);
    a[in++]=b[i];
}
void wrev(int i){
    if(!a[i]){
        print_rev(i-1);     return ;
    }
    else if(a[i]=='_'){
        print_rev(i-1);     s=i+1;
        printf("%c",a[i]);
    }
    wrev(i+1);
}
int main(){
    gets(b);
    rev(0);
    wrev(0);
    return 0;
}
