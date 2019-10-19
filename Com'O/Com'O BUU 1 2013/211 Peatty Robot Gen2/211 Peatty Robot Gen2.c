#include<stdio.h>
#include<string.h>
int main()
{
    int i,len,path=0;
    char a[200],point[4]={'N','E','S','W'};
    scanf(" %s",a);
    len=strlen(a);
    for(i=0;i<len;i++)
    {
        if(a[i]=='Z')
        {
            path=0;
            printf("Z");
            continue;
        }
        while(a[i]!=point[path%4])
        {
            printf("R");
            path++;
        }
        printf("F");
    }
    printf("\n");
    return 0;
}
