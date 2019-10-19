#include<stdio.h>
#include<string.h>

int main()
{
    int n,len,i,j;
    char a[12000],b[12000];
    scanf("%d",&n);

    while(n--)
    {
        scanf("%s",a);
        len=strlen(a);
        for(i=1;i<=len;i++)
        {
            if(!(len%i))
                strncpy(b,a,i);
                for(j=0;j+i-1<len;j+=i)
                    if(strncmp(&a[j],b,i))
                        break;
                if(j==len)
                {
                    printf("%d\n",len/i);
                    break;
                }
        }
    }
    return 0;
}
