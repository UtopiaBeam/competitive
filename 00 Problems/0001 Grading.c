#include<stdio.h>

main()
{
    int a,x,y,z;
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&z);
    a=x+y+z;
    if(a<80)
        if(a<75)
            if(a<70)
                if(a<65)
                    if(a<60)
                        if(a<55)
                            if(a<50)
                                printf("F");
                            else
                                printf("D");
                        else
                            printf("D+");
                    else
                        printf("C");
                else
                    printf("C+");
            else
                printf("B");
        else
            printf("B+");
    else
        printf("A");

}
