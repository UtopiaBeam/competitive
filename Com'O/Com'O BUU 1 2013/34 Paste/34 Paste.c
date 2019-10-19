#include<stdio.h>
#include<math.h>

int main()
{
    int N,W,H,l[1000],ML,i=0;
    scanf("%d %d %d\n",&N,&W,&H);
    while(i<N)
    {
        scanf("%d",&l[i]);
        i++;
    }
    ML=sqrt(pow(W,2)+pow(H,2));
    i=0;
    while(i<N)
    {
        if(l[i]<=ML)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");

        }
        i++;
    }
    return 0;
}
