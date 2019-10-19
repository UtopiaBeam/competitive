#include<stdio.h>
#include<math.h>

int main()
{
    int n,i;
    int check;
    scanf("%d",&n);
    if(n==0||n==1)
    {
        printf("No\n");
        return 0;
    }
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i) check=1;
        else
        {
            check=0;
            break;
        }
    }
    if(check)   printf("Yes\n");
    else        printf("No\n");
    return 0;
}
