#include<cstdio>
char a[100005],b[100005];
int p=0;
int main(){
    scanf(" %s %s",a,b);
    for(int i=0;a[i];i++)
        if(a[i]!=b[i])  p++;
    if(p%2)     printf("impossible\n");
    else{
        p/=2;
        for(int i=0;p && a[i];i++)
            if(a[i]!=b[i])  a[i]=b[i],p--;
        printf("%s\n",a);
    }
    return 0;
}