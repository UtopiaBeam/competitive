#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,cnt,len=0;
    char a[20][50];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        cnt=0;
        scanf(" %s",a[i]);
        len=strlen(a[i]);
        for(j=0;j<=len-1;j++)
        {
            if((a[i][j]=='a' || a[i][j]=='e' || a[i][j]=='i' ||a[i][j]=='o' || a[i][j]=='u')
            && (a[i][j+1]!='a' && a[i][j+1]!='e' && a[i][j+1]!='i' && a[i][j+1]!='o' && a[i][j+1]!='u'))
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
