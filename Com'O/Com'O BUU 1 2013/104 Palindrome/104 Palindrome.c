#include<stdio.h>
#include<string.h>
#include<ctype.h>
int len,mid,chk=1;
char a[220];
void palin(){
    int i;
    for(i=0;i<mid;i++){
        a[i]=tolower(a[i]);
        a[len-i-1]=tolower(a[len-i-1]);
        if(a[i]!=a[len-i-1]){
            printf("No\n");
            return ;
        }
    }
    for(i=0;i<mid/2;i++)
        if(a[i]!=a[mid-i-1]){
            printf("Palindrome\n");
            return ;
        }
    for(i=mid+1;i<len;i++)
        if(a[i]!=a[len-i-1]){
            printf("Palindrome\n");
            return ;
        }
    printf("Double Palindrome\n");
}
int main(){
    int q,i;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",a);
        len=strlen(a),mid=len/2;
        palin();
    }
    return 0;
}
