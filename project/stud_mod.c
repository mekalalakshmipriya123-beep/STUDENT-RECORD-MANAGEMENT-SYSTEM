/* stud_mod.c */

#include "student.h"

void stud_mod(void)
{
    char ch, ch2;
    int roll;
    char name[30];

    ST *temp;

    if(head == NULL)
    {
        printf("\nNo Records Available...\n");
        return;
    }

    printf("\nR/r : Search by Roll Number\n");
    printf("N/n : Search by Name\n");
    printf("P/p : Search by Percentage\n");

    printf("\nEnter Your Choice : ");
    scanf(" %c",&ch);

    temp = head;

    switch(ch)
    {
        case 'R':
        case 'r':

            printf("Enter Roll Number : ");
            scanf("%d",&roll);

            while(temp)
            {
                if(temp->roll == roll)
                    break;
                temp = temp->next;
            }

            if(temp == NULL)
            {
                printf("\nRecord Not Found...\n");
                return;
            }
            break;

        case 'N':
        case 'n':

            printf("Enter Name : ");
            scanf(" %[^\n]",name);

            printf("\nMatching Records:\n");
            while(temp)
            {
                if(strcmp(temp->name,name)==0)
                {
                    printf("%d %s %.2f\n",
                        temp->roll,
                        temp->name,
                        temp->per);
                }
                temp = temp->next;
            }

            printf("\nEnter Roll Number to Modify : ");
            scanf("%d",&roll);

            temp = head;
            while(temp && temp->roll != roll)
                temp = temp->next;

            if(temp == NULL)
            {
                printf("\nRecord Not Found...\n");
                return;
            }
            break;

        case 'P':
        case 'p':

            printf("Enter Percentage : ");
            scanf("%f",&temp->per);

            printf("\nEnter Roll Number to Modify : ");
            scanf("%d",&roll);

            temp = head;
            while(temp && temp->roll != roll)
                temp = temp->next;

            if(temp == NULL)
            {
                printf("\nRecord Not Found...\n");
                return;
            }
            break;

        default:
            printf("\nInvalid Choice...\n");
            return;
    }

    /* Modify Section */
    printf("\nN/n : Modify Name\n");
    printf("P/p : Modify Percentage\n");

    printf("\nEnter Your Choice : ");
    scanf(" %c",&ch2);

    switch(ch2)
    {
        case 'N':
        case 'n':
            printf("Enter New Name : ");
            scanf(" %[^\n]",temp->name);
            break;

        case 'P':
        case 'p':
            printf("Enter New Percentage : ");
            scanf("%f",&temp->per);
            break;

        default:
            printf("\nInvalid Choice...\n");
            return;
    }

    printf("\nRecord Modified Successfully...\n");
}
