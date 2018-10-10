#include<stdio.h>

int main()
{
    int n,i,j,mod[10],cnt=0,check;
    for(i=0;i<10;i++)
    {
        check=1;
        scanf("%d",&n);
        mod[i]=n%42;
        for(j=0;j<i;j++)
        {
            if(mod[i]==mod[j])
            {
                check=0;
                break;
            }
        }
        if(check)   cnt++;
    }

    printf("%d\n",cnt);
    return 0;
}
