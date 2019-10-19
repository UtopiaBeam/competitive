#include<cstdio>
#include<cstring>
#include<cctype>
char a[105],b[105],c[105],t[605];
char *cat(char *a,char *b,char *c){
    return strcat(a,strcat(b,c));
}
int main(){
    scanf(" %s %s %s",a,b,c);
    int n,lena=strlen(a),lenb=strlen(b),lenc=strlen(c);
    for(int i=0;i<lena;i++){
        if(a[i]=='-'||a[i]==','||a[i]==';'||a[i]=='_')  strcpy(a+i,a+i+1),lena--,i--;
        else if(isupper(a[i]))   a[i]=tolower(a[i]);
    }
    for(int i=0;i<lenb;i++){
        if(b[i]=='-'||b[i]==','||b[i]==';'||b[i]=='_')  strcpy(b+i,b+i+1),lenb--,i--;
        else if(isupper(b[i]))   b[i]=tolower(b[i]);
    }
    for(int i=0;i<lenc;i++){
        if(c[i]=='-'||c[i]==','||c[i]==';'||c[i]=='_')  strcpy(c+i,c+i+1),lenc--,i--;
        else if(isupper(c[i]))   c[i]=tolower(c[i]);
    }
    scanf("%d",&n);
    while(n--){
        scanf(" %s",t);
        int lent=strlen(t);
        for(int i=0;i<lent;i++){
            if(t[i]=='-'||t[i]==','||t[i]==';'||t[i]=='_')  strcpy(t+i,t+i+1),lent--,i--;
            else if(isupper(t[i]))   t[i]=tolower(t[i]);
        }
    }
    return 0;
}
