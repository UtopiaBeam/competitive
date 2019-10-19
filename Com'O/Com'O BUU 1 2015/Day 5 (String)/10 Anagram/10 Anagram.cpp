#include<cstdio>
int n;
char a[202];
int main(){
    scanf("%d ",&n);
    while(n--){
        int c[30]={},chk=0;
        gets(a);
        for(int i=0,ch=1;a[i];i++){
            if(a[i]==':')   ch=0;
            if(ch){
                if(a[i]>='A' && a[i]<='Z')  c[a[i]-'A']++;
                if(a[i]>='a' && a[i]<='z')  c[a[i]-'a']++;
            }
            else{
                if(a[i]>='A' && a[i]<='Z')  c[a[i]-'A']--;
                if(a[i]>='a' && a[i]<='z')  c[a[i]-'a']--;
            }
        }
        for(int i=0;i<26 && !chk;i++)
            if(c[i]!=0)     chk=1;
        printf("%d\n",chk);
    }
    return 0;
}
