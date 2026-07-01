/* stud_del.c */

#include "student.h"

void stud_del(void)
{
    char ch;
    int roll;
    char name[30];

    ST *temp, *prev;

    if(head == NULL)
    {
        printf("\nNo Records Available...\n");
        return;
    }

    printf("\nR/r : Delete using Roll Number\n");
    printf("N/n : Delete using Name\n");

    printf("\nEnter Your Choice : ");
    scanf(" %c",&ch);

    switch(ch)
    {
        case 'R':
        case 'r':

            printf("Enter Roll Number : ");
            scanf("%d",&roll);

            temp = head;
            prev = NULL;

            while(temp)
            {
                if(temp->roll == roll)
                {
                    if(prev == NULL)
                        head = temp->next;
                    else
                        prev->next = temp->next;

                    free(temp);

                    printf("\nRecord Deleted Successfully...\n");
                    return;
                }

                prev = temp;
                temp = temp->next;
            }

            printf("\nRoll Number Not Found...\n");
            break;


        case 'N':
        case 'n':

            printf("Enter Name : ");
            scanf(" %[^\n]",name);

            temp = head;

            printf("\nMatching Records\n");
            printf("--------------------------------------------\n");
            printf("%-10s %-20s %-10s\n",
                    "Roll","Name","Per");
            printf("--------------------------------------------\n");

            int found = 0;

            while(temp)
            {
                if(strcmp(temp->name,name)==0)
                {
                    printf("%-10d %-20s %-10.2f\n",
                            temp->roll,
                            temp->name,
                            temp->per);
                    found = 1;
                }

                temp = temp->next;
            }

            if(found==0)
            {
                printf("\nNo Matching Record Found...\n");
                return;
            }

            printf("\nEnter Roll Number to Delete : ");
            scanf("%d",&roll);

            temp = head;
            prev = NULL;

            while(temp)
            {
                if(temp->roll==roll)
                {
                    if(prev==NULL)
                        head=temp->next;
                    else
                        prev->next=temp->next;

                    free(temp);

                    printf("\nRecord Deleted Successfully...\n");
                    return;
                }

                prev=temp;
                temp=temp->next;
            }

            printf("\nRoll Number Not Found...\n");
            break;

        default:

            printf("\nInvalid Choice...\n");
    }
}
