#include<cstdio>
#include<map>
using namespace std;
int a[60],b[50];
char str[3000005];
void add(char ch,int *t){
    if('a'<=ch && ch<='z')  t[ch-'a']++;
    else    t[ch-'A'+26]++;
}
void del(char ch,int *t){
    if('a'<=ch && ch<='z')  t[ch-'a']--;
    else    t[ch-'A'+26]--;
}
int main(){
    int n,m,ans=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        char ch;
        scanf(" %c",&ch);
        add(ch,a);
    }
    scanf(" %s",str);
    for(int i=0;i<n;i++)
        add(str[i],b);
    if(n==m)
        for(int i=0;i<52;i++){
            if(a[i]!=b[i])      break;
            if(i==51)      ans++;
        }
    else for(int i=n;i<m;i++){
            for(int j=0;j<52;j++){
                if(a[j]!=b[j])      break;
                if(j==51)   ans++;
            }
            add(str[i],b),del(str[i-n],b);
        }
    for(int i=0;i<52;i++){
        if(a[i]!=b[i])      break;
        if(i==51)       ans++;
    }
    printf("%d\n",ans);
    return 0;
}
