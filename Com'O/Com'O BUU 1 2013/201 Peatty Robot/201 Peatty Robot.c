#include<stdio.h>

int main()
{
    int x=0,y=0;
    char ch;

    while((ch=getchar())!=EOF)
    {
        if(ch=='N')
            y++;
        else if(ch=='S')
            y--;
        else if(ch=='E')
            x++;
        else if(ch=='W')
            x--;
        else if(ch=='Z')
        {
            x=0;
            y=0;
        }
    }
    printf("%d %d",x,y);

    return 0;
}
