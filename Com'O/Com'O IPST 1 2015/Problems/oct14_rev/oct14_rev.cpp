#include<cstdio>
char a[1002];
void rev(int i){
    if(a[i]){
        rev(i+1);   printf("%c",a[i]);
    }
}
int main(){
    scanf(" %s",a);
    rev(0);
    return 0;
}
