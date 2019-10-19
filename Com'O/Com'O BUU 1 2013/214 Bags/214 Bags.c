#include<stdio.h>

int main()
{
    int q,n,k,i,cnt;
    scanf("%d",&q);

    for(i=0;i<q;i++)
    {
        cnt=0;
        scanf("%d %d",&n,&k);
        if(k==13)   k--;
        else if(k==14)  cnt++;
        while(n>=0)
        {
            cnt++;
            n-=k;
        }
        printf("%d\n",cnt);
    }

    return 0;
}
