#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,n,index;
    scanf("%d",&n);
    double h[n+1],max;
    char unit[n+1],name[n+1][150];
    for(i=1;i<=n;i++)
    {
        scanf(" %s %lf %s",&name[i],&h[i],unit);
        if(!strcmp(unit,"mm"))  h[i]/=1000.0;
        if(!strcmp(unit,"cm"))  h[i]/=100.0;
        if(!strcmp(unit,"dm"))  h[i]/=10.0;
    }
    for(i=1;i<=5;i++)
    {
        max=0.0;
        for(j=1;j<=n;j++)
        {
            if(max<h[j])
            {
                max=h[j];
                index=j;
            }
            if(max-h[j]<0.000001 && h[j]-max>-0.000001)
            {
                if(strcmp(name[index],name[j])>0)   index=j;
            }
        }
        h[index]=0;
        printf("%s\n",name[index]);
    }
    return 0;
}
