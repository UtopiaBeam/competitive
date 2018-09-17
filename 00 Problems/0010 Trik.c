#include<stdio.h>
#include<string.h>

int main()
{
    char key[70];
    int i,len,ball[3]={1,0,0},t;
    scanf(" %s",key);
    len=strlen(key);
    for(i=0;i<len;i++)
    {
        if(key[i]=='A')
        {
            t=ball[0],ball[0]=ball[1],ball[1]=t;
        }
        if(key[i]=='B')
        {
            t=ball[1],ball[1]=ball[2],ball[2]=t;
        }
        if(key[i]=='C')
        {
            t=ball[2],ball[2]=ball[0],ball[0]=t;
        }
    }
    for(i=0;i<3;i++)
        if(ball[i]==1)  printf("%d\n",i+1);
    return 0;
}
