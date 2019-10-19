#include<cstdio>
char a[1002];
int from=0;
void rev(int i){
    if(i>=from){
        printf("%c",a[i]);
        rev(i-1);
    }
}
void wordrev(int i){
    if(a[i]=='\0')      rev(i-1);
    else{
        if(a[i]=='_'){
            rev(i-1);
            from=i+1;
            printf("_");
        }
        wordrev(i+1);
    }
}
int main(){
    scanf(" %s",a);
    wordrev(0);
    return 0;
}
