#include<stdio.h>
#include<string.h>

int main()
{
    int i,len,check3=0,check11=0;
    char a[1000010];
    scanf(" %s",a);
    len=strlen(a);
    for(i=0;i<len;i++)
    {
        check3+=a[i]-'0';
        if((len-i)%2)   check11+=a[i]-'0';
        else            check11-=a[i]-'0';
    }
    check3%=3;  check11%=11;
    if(check11<0)   check11+=11;
    printf("%d %d\n",check3,check11);
    return 0;
}
