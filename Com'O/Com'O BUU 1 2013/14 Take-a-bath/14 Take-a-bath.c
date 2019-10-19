#include<stdio.h>

int main()
{
    int i,m,d,cnt=0;
    scanf("%d %d",&m,&d);

    for(i=1;i<=m;i++)
    {
        if((i-1+d)%7==4)
            if(i%2)
                cnt+=3;
            else
                cnt+=5;
        else if((i-1+d)%7==6)
            if(i%2)
                cnt+=2;
            else
                cnt+=5;
        else
            cnt+=5;
    }

    printf("%d\n",cnt);

    return 0;
}
