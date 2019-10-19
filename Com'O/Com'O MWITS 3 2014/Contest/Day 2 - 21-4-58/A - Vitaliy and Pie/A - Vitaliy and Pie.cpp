#include<cstdio>
#include<cctype>
int key[30];
int main(){
    int n,cnt=0;
    scanf("%d ",&n);
    for(int i=0;i<2*n-2;i++){
        char ch;
        scanf("%c",&ch);
        if(islower(ch))     key[ch-'a']++;
        else if(key[ch-'A'])    key[ch-'A']--;
        else    cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
