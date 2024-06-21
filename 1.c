#include<stdio.h>
#include<stdlib.h>
int N, size;
struct student
{
    int regno;
    char name[20];
    int marks[3];
    float average;
};
 void read (struct student *);
 void disp (struct student *);
 void average(struct student *);
 int main()
 {
     struct student *sp;
     printf("enter the size\n");
     scanf("%d", &size);
     sp = (struct student *)malloc(size * sizeof(struct student));
     int choice;
     for (;;)
     {
         printf("enter choice\n1.read \n 2.display\n 3.average\n");
         scanf("%d", &choice);
         switch ( choice)
         {
         case 1:
             read(sp);
             break;
        case 2:
            disp(sp);
            break;
        case 3:
            average(sp);
            break;
            default:
                printf("invalid choice\n");
                free(sp);
                sp = NULL;
                exit(0);
         }
     }
     return 0;
 }
 void read(struct student*sp)
 {
     int i, j;
     printf("enter no of students information\n");
     scanf("%d", &N);
     if ( N>size)
     {
         printf("insufficient space\n");
         printf("creating space by allocating memory\n");
     }
     for (i = 0; i < N;i++)
     {
         printf("enter regno name of the student%d\n", i + 1);
         scanf("%d%s", &(sp + i)->regno, (sp + i)->name);
         printf("enter the marks of student in three tests\n");
         for (j = 0; j < 3;j++)
         {
             scanf("%d", &(sp + i)->marks[j]);
         }
         }
         }
         void disp(struct student*sp)
         {
             int i, j;
             if(N==0)
             {
                 printf("list empty");
                 return;
             }
             printf("regno\t name\t test1\t test2\t test3\t\n");
             for (i = 0; i < N;i++)
             {
                 printf("%d\t%s\t", (sp + i)->regno, (sp + i)->name);
                 for (j = 0; j < 3;j++)
                 {
                     printf("%d\t", (sp + i)->marks[j]);
              }
              printf("\n");
             }
        }
        void average(struct student*sp)
        {
            int i, j, k, temp, sum[N];
            for (i = 0; i < N;i++)
            {
                for (j = 0; j < 2;j++)
                {
                    for (k = 0; k < 3 - j - 1;k++)
                    {
                        if ( (sp+i)->marks[k]>(sp+i)->marks[k+1])
                        {
                            temp = (sp + i)->marks[k];
                            (sp + i)->marks[k] = (sp + i)->marks[k + 1];
                            (sp + i)->marks[k + 1] = temp;
                        }
                    }
                 }
            }
            for (i = 0; i < N;i++)
            {
                sum[i] = (sp + i)->marks[1] + (sp + i)->marks[2];
                printf("average of best of two student%dis%f\n", i + 1, (float)(sum[i] / 2.0));
            }

        }
