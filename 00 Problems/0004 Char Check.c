#include<stdio.h>

int main()
{
    int small=0,capital=0;
    char a;

    a=getchar();
    if(a>='a'&&a<='z')
        small++;
    else if(a>='A'&&a<='Z')
        capital++;
    while(a!=EOF)
    {
        a=getchar();
        if(a>='a'&&a<='z')
            small++;
        else if(a>='A'&&a<='Z')
            capital++;
    }
    if(small==0)
        printf("All Capital Letter");
    else if(capital==0)
        printf("All Small Letter");
    else
        printf("Mix");

    return 0;
}
