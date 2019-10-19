#include<cstdio>
char a[100005];
bool c1=false,c2=false,c3=false,c4=false;
int main(){
    gets(a);
    for(int i=0;a[i];i++){
        if(a[i]=='A' && a[i+1]=='B' && !c1)    c1=true,i++;
        else if(a[i]=='B' && a[i+1]=='A' && !c2)   c2=true,i++;
        if(a[i]=='B' && a[i+1]=='A' && !c3)    c3=true,i++;
        else if(a[i]=='A' && a[i+1]=='B' && !c4)   c4=true,i++;
    }
    if((c1 && c2) || (c3 && c4))    printf("YES\n");
    else    printf("NO\n");
    return 0;
}
