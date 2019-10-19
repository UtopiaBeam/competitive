#include<stdio.h>

int main()
{
    int i,Student[5],min,max,rank_min,rank_max,chk_min,chk_max;
    double Avg=0;
    for(i=0;i<5;i++){
        scanf("%d",&Student[i]);

    if(Student[i]<80)
        if(Student[i]<75)
            if(Student[i]<70)
                if(Student[i]<65)
                    if(Student[i]<60)
                        if(Student[i]<55)
                            if(Student[i]<50)
                                printf("F\n");
                            else
                                printf("D\n");
                        else
                            printf("D+\n");
                    else
                        printf("C\n");
                else
                    printf("C+\n");
            else
                printf("B\n");
        else
            printf("B+\n");
    else
        printf("A\n");
    Avg+=Student[i];
    }
    min=999;
    max=-1;

    for(i=0;i<5;i++){
        if(Student[i]<min){
            min=Student[i];
            rank_min=i+1;
            chk_min=0;
            }
        else if(Student[i]==min){
            printf("None\n");
            chk_min=1;
            break;
            }
    }
    for(i=0;i<5;i++){
        if(Student[i]>max){
            max=Student[i];
            rank_max=i+1;
            chk_max=0;
            }
        else if(Student[i]==max){
            printf("None\n");
            chk_max=1;
            break;
            }
        }
    if(chk_max==0)
    printf("Student%d\n",rank_max);
    if(chk_min==0)
    printf("Student%d\n",rank_min);
    printf("Average = %.2lf",Avg/5);

    return 0;
}
