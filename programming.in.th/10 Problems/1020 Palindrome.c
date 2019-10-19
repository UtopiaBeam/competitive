#include<stdio.h>
#include<string.h>
#include<ctype.h>
int len,mid,chk=1;
char a[220];
int main(){
    int i;
    scanf(" %s",a);
    len=strlen(a),mid=len/2;
    for(i=0;i<mid;i++){
        a[i]=tolower(a[i]);
        a[len-i-1]=tolower(a[len-i-1]);
        if(a[i]!=a[len-i-1]){
            printf("No\n");
            return 0;
        }
    }
    for(i=0;i<mid/2;i++)
        if(a[i]!=a[mid-i-1]){
            printf("Palindrome\n");
            return 0;
        }
    for(i=mid+1;i<len;i++)
        if(a[i]!=a[len-i-1]){
            printf("Palindrome\n");
            return 0;
        }
    printf("Double Palindrome\n");
    return 0;
}
