#include<stdio.h>

int main()
{
    int h1,m1,s1,h2,m2,s2,t;
    scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
    if(h1>h2)
    {
        t=(h1+24-h2)*3600+(m1+60-m2)*60+s1-s2+60;
        printf("%02d:%02d:%02d",24-(t/3600)%24,60-(t/60)%60,60-t%60);
    }

    else
    {
        t=(h2-h1)*3600+(m2-m1)*60+s2-s1;
        printf("%02d:%02d:%02d",(t/3600)%24,(t/60)%60,t%60);
    }

    return 0;
}
