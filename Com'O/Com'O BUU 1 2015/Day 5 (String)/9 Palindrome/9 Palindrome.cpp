#include<cstdio>
#include<cctype>
#include<cstring>
char a[50002],b[50002];
int n;
int main(){
    scanf("%d ",&n);
    while(n--){
        gets(b);
        int len=0,chk=1;
        for(int i=0;b[i];i++){
            if(isalpha(b[i]))   a[len++]=tolower(b[i]);
            else if(isdigit(b[i]))  a[len++]=b[i];
        }
        a[len]='\0';
        for(int i=0;i<len;i++){
            if(a[i]!=a[len-i-1]){
                printf("No\n");
                chk=0;  break;
            }
        }
        if(!chk)    continue;
        int mid=len/2;
        for(int i=0;i<mid;i++)
            if(a[i]!=a[mid-i-1]){
                printf("Palindrome\n");
                chk=0;  break;
            }
        if(!chk)    continue;
        for(int i=mid+1;i<len;i++)
            if(a[i]!=a[len-i-1]){
                printf("Palindrome\n");
                chk=0;  break;
            }
        if(chk) printf("Double Palindrome\n");
    }
    return 0;
}
