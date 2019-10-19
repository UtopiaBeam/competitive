#include<cstdio>
#include<cstring>
char a[1002];
int to=0;
void rev(int i){
    if(i<=to){
        printf("%c",a[i]);
        rev(i+1);
    }
}
void wordrev(int i){
    if(i<0)      rev(i+1);
    else{
        if(a[i]=='_'){
            rev(i+1);
            to=i-1;
            printf("_");
        }
        wordrev(i-1);
    }
}
int main(){
    scanf(" %s",a);
    wordrev(to=strlen(a)-1);
    return 0;
}

