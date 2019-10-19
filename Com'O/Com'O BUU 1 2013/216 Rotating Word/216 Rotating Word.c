#include<stdio.h>
#include<string.h>

int main()
{
    int n,i,len_a;
    char a[1200];
    gets(a);
    scanf("%d",&n);
    char b[n+2];

    len_a=strlen(a),n;
    strncpy(b,&a[len_a-n],n);
    for(i=len_a-1;i>=0;i--)
        a[i]=a[i-n];
    strncpy(a,b,n);

    printf("%s\n",a);

    return 0;
}
