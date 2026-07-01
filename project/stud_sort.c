/* stud_sort.c */

#include "student.h"

void stud_sort(void)
{
    char ch;
    ST *i, *j;
    ST temp;

    if(head == NULL)
    {
        printf("\nNo Records to Sort...\n");
        return;
    }

    printf("\nN/n : Sort by Name\n");
    printf("P/p : Sort by Percentage\n");

    printf("\nEnter Your Choice : ");
    scanf(" %c",&ch);

    switch(ch)
    {
        /* SORT BY NAME */
        case 'N':
        case 'n':

            for(i = head; i != NULL; i = i->next)
            {
                for(j = i->next; j != NULL; j = j->next)
                {
                    if(strcmp(i->name, j->name) > 0)
                    {
                        temp.roll = i->roll;
                        strcpy(temp.name, i->name);
                        temp.per = i->per;

                        i->roll = j->roll;
                        strcpy(i->name, j->name);
                        i->per = j->per;

                        j->roll = temp.roll;
                        strcpy(j->name, temp.name);
                        j->per = temp.per;
                    }
                }
            }

            printf("\nSorted by Name Successfully...\n");
	    stud_show();
            break;

        /* SORT BY PERCENTAGE */
        case 'P':
        case 'p':

            for(i = head; i != NULL; i = i->next)
            {
                for(j = i->next; j != NULL; j = j->next)
                {
                    if(i->per > j->per)
                    {
                        temp.roll = i->roll;
                        strcpy(temp.name, i->name);
                        temp.per = i->per;

                        i->roll = j->roll;
                        strcpy(i->name, j->name);
                        i->per = j->per;

                        j->roll = temp.roll;
                        strcpy(j->name, temp.name);
                        j->per = temp.per;
                    }
                }
            }

            printf("\nSorted by Percentage Successfully...\n");
	    stud_show();
            break;

        default:
            printf("\nInvalid Choice...\n");
    }
}
